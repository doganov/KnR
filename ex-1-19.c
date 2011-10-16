#include <stdio.h>

#define MAXLINE 1000 /* максимална дължина на входния ред */

int getline(char line[], int maxline);
int length(char s[]);
void trimr(char s[]);
void reverse(char s[]);

/* Упражнение 1.19.  Напишете функция reverse(s), която обръща
   символния низ s.  Използвайте я, за да напишете програма, която
   преобръща входа си ред по ред. */

main()
{
  int len; /* дължина на текущия ред */
  char line[MAXLINE]; /* текущ входен ред */

  while ((len = getline(line, MAXLINE)) > 0) {
    trimr(line);
    reverse(line);
    printf("%s\n", line);
  }
  return 0;
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

/* strlength: връща броя символи в един ASCIIZ-стринг, без да брои
   терминиращия символ '\0'. */
int length(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i);

  return i;
}

/* trimr: бастисва всякакъв whitespace в края на символния низ s. */
void trimr(char s[]) {
  int len;
  int i;

  len = length(s);

  if (len == 0) return;
  
  for (i = len - 1;
       i >= 0 && ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'));
       --i)
    s[i] = '\0';
}

/* reverse: обръща реда на символите в низа s. */
void reverse(char s[]) {
  int len;
  int half;
  int i;
  char tmp;

  len = length(s);

  half = len / 2;
  
  for (i = 0; i < half; ++i) {
    tmp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = tmp;
  }
}
