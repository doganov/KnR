#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* максимален брой редове, които могат да се
                         сортират */

char *lineptr[MAXLINES]; /* указатели към текстовите редове */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* сортира входните редове */
main()
{
  int nlines; /* брой прочетени от входа редове */

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000 /* максимална дължина на един входен ред */
int getline(char *, int);
char *alloc(int);

/* readlines: чете редове от входа */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if ((nlines >= maxlines) || ((p = alloc(len)) == NULL))
      return -1;
    else {
      line[len-1] = '\0'; /* изтрива новия ред */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: изписва редовете на изхода */
void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* getline: чете ред в s, връща дължината му */
int getline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

#define ALLOCSIZE 10000 /* големина на наличното пространство */

static char allocbuf[ALLOCSIZE]; /* памет за alloc */
static char *allocp = allocbuf; /* следваща свободна позиция */

char *alloc(int n) /* връща указател към n символа */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* вмества се */
    allocp += n;
    return allocp - n; /* старата стойност на p */
  } else               /* няма достатъчно място */
    return 0;
}

void afree(char *p) /* освобождава паметта, към която сочи p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

/* qsort: сортира v[left]...v[right] във възходящ ред */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) /* не прави нищо, ако масивът съдържа по-малко */
    return;          /* от два елемента */
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: разменя v[i] и v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
