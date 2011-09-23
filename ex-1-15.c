#include <stdio.h>

/* Упражнение 1.15.  Отпечатва таблица по Фаренхайт и Целзий за fahr =
   0, 20 ... 300 използвайки функция. */

int celsius(int fahr);

main()
{
  int fahr;
  int lower, upper, step;

  lower = 0; /* долна граница на температурната таблица */
  upper = 300; /* горна граница */
  step = 20; /* големина на стъпката */

  fahr = lower;
  while (fahr <= upper) {
    printf("%d\t%d\n", fahr, celsius(fahr));
    fahr = fahr + step;
  }
}

int celsius(int fahr)
{
  return 5 * (fahr-32) / 9;
}
