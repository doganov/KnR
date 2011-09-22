#include <stdio.h>

/* Упражнение 1.13.  Отпечатва хисторграма на дължината на думите от
   входа. */

#define IN  1 /* вътре в дума сме */
#define OUT 0 /* извън дума сме */
#define MAX_WORD_LENGTH 30 /* ако срещнем по-дълга дума сме тотално
                              преебани; на този етап от книгата още не
                              знаем как да се справим с това
                              ограничение, нито как да обработим
                              евентуалното му нарушение */

main()
{
  int lengths[MAX_WORD_LENGTH];

  /* инициализираме на масива */
  for (int i = 0; i < MAX_WORD_LENGTH; ++i)
    lengths[i] = 0;

  /* събираме данните */
  int c, state, length, maxlength;

  state = OUT;
  length = 0;
  maxlength = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        ++lengths[length - 1];
      }
    }
    else {
      if (state == OUT) {
        state = IN;
        length = 0;
      }
      ++length;
      if (length > maxlength)
        maxlength = length;
    }    
  }

  /* последната дума може да не завършва с whitespace; хайде да я
     обработим и нея */
  if (state == IN)
    ++lengths[length - 1];

  /* извеждаме хистограмата */
  for (int l = 0; l < maxlength; l++) {
    printf("%2d ", l + 1);
    for (int i = 0; i < lengths[l]; i++)
      printf("-");
    /* printf("%d", lengths[l]); */
    printf("\n");
  }
}
