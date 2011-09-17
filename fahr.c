#include <stdio.h>

/* Отпечатва таблица по Фаренхайт и Целзий
   за fahr = 0, 20 ... 300 */

main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0; /* долна граница на температурната таблица */
  upper = 300; /* горна граница */
  step = 20; /* големина на стъпката */

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}
