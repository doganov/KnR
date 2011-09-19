#include <stdio.h>

/* Упражнение 1.8. Преброяване на шпациите, табулациите и новите
   редове от входа. */

main()
{
  int c, sp, tab, nl;

  sp = tab = nl = 0;

  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++sp;
    else
      if (c == '\t')
        ++tab;
      else
        if (c == '\n')
          ++nl;

  printf("шпации: %d\tтабулации: %d\tнови редове: %d\n", sp, tab, nl);
}
