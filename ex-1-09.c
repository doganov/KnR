#include <stdio.h>

/* Упражнение 1.8. Копира входа си на изхода, като замества всеки низ,
   съставен от една или повече шпации, с една-единствена шпация. */

main()
{
  int c, prev;

  prev = EOF;

  while ((c = getchar()) != EOF) {
    if ((c != ' ') || (prev != ' '))
      putchar(c);
    prev = c;
  }

}