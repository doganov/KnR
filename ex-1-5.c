#include <stdio.h>

/* Отпечатва таблица по Фаренхайт и Целзий
   за fahr = 300, 280 ... 0; */

main()
{
  int fahr;

  printf("Упражнение 1.5. Температури по Фаренхайт и Целзий\n\n");
  printf("°F \t  °C\n");
  printf("---\t------\n");

  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));

}
