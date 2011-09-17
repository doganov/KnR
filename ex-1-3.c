#include <stdio.h>

/* Отпечатва таблица по Фаренхайт и Целзий
   за fahr = 0, 20 ... 300; версия с числа с плаваща запетая */

main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* долна граница на температурната таблица */
  upper = 300; /* горна граница */
  step = 20; /* големина на стъпката */

  printf("Упражнение 1.3. Температури по Фаренхайт и Целзий\n\n");
  printf("°F \t  °C\n");
  printf("---\t------\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
