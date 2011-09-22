#include <stdio.h>

/* Отпечатва таблица по Целзий и Фаренхайт
   за celsius = 0, 20 ... 300; */

main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* долна граница на температурната таблица */
  upper = 300; /* горна граница */
  step = 20; /* големина на стъпката */

  printf("Упражнение 1.4. Температури по Целзий и Фаренхайт\n\n");
  printf("°C \t °F\n");
  printf("---\t-----\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0/5.0) * celsius) + 32.0;
    printf("%3.0f\t%5.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
