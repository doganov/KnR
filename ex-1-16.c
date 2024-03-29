#include <stdio.h>

#define MAXLINE 1000 /* максимална дължина на входния ред */

int getline(char line[], int maxline);

/* Упражнение 1.16.  Трудно е да се каже „Какво е имал предвид
   авторът“ когато е задавал това задание.  Според нашето тълкуване
   тази програма трябва да отпечатва дължината и съдържанието на всеки
   ред, без значение дали е най-дългия или не.  Под „дължина на ред“
   се разбира броят символи на реда, без да се брои знакът за нов ред
   (ако има такъв) накрая.  Разбира се, терминиращият знак \0 също не
   се брои. */

main()
{
  int len; /* дължина на текущия ред */
  char line[MAXLINE]; /* текущ входен ред */

  while ((len = getline(line, MAXLINE)) > 0) {
    if (line[len - 1] == '\n') {
      len = len - 1;
      line[len] = '\0';
    }
    printf("%3d %s\n", len, line);
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
