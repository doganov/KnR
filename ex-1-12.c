#include <stdio.h>

/* Упражнение 1.12.  Отпечатва входа си, като всяка дума е поставена
   на отделен ред. */

#define IN  1 /* вътре в дума сме */
#define OUT 0 /* извън дума сме */

main()
{
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    }
    else {
      state = IN;
      putchar(c);
    }
  }
}
