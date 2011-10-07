#include <stdio.h>

#define MAXLINE 1000 /* максимална дължина на входния ред */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Упражнение 1.17.  Отпечатва всички входни редове, които са по-дълги
   от 80 символа. */

main()
{
  int len; /* дължина на текущия ред */
  char line[MAXLINE]; /* текущ входен ред */

  while ((len = getline(line, MAXLINE)) > 0) {
    if (line[len - 1] == '\n') {
      len = len - 1;
      line[len] = '\0';
    }
    if (len > 80)
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
