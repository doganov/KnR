#include <stdio.h>

#define MAXLINE 1000 /* максимална дължина на входния ред */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* отпечатва най-дългия входен ред */
main()
{
  int len; /* дължина на текущия ред */
  int max; /* максималната дължина, намерена до момента */
  char line[MAXLINE]; /* текущ входен ред */
  char longest[MAXLINE]; /* тук се запазва най-дългият ред */

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /* имало е ред на входа */
    printf("%s", longest);
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

/* copy: копира 'from' в 'to'; предполагаме, че to е достатъчно
   голям */

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
