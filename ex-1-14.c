#include <stdio.h>

/* Упражнение 1.14.  Отпечатва хисторграма, отразяваща колко често се
   срещат различните символи на входа. */

#define CHAR_LENGTH 256 /* предполагаме 8-битово кодиране */

main()
{
  int counts[CHAR_LENGTH];

  /* инициализираме на масива */
  for (int i = 0; i < CHAR_LENGTH; ++i)
    counts[i] = 0;

  /* събираме данните */
  int c, minc, maxc;

  minc = CHAR_LENGTH;
  maxc = 0;
  while ((c = getchar()) != EOF) {
    if (c < minc)
      minc = c;

    if (c > maxc)
      maxc = c;

    ++counts[c];
  }

  /* извеждаме хистограмата */
  for (int l = minc; l <= maxc; ++l) {
    printf("%3d ", l);
    for (int i = 0; i < counts[l]; ++i)
      printf("-");
    /* printf("%d", counts[l]); */
    printf("\n");
  }
}
