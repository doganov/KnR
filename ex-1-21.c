#include <stdio.h>

/* Упражнение 1.21.  Напишете програма entab, която заменя низ от
   шпации с минимален брой табулации и шпации, така че да се запази
   същото празно пространство.  Използвайте същите позиции на
   табулатора както при detab.  Когато и табулатор, и една-единствена
   шпация удовлетворяват условието да стигнат до позицията на
   табулатора, кое от двете ще предпочетете? */

#define N 8 /* разстояние между отделните позиции на табулатора */
#define TRUE 1
#define FALSE 0
#define SPACE ' '

int pos; /* текуща позиция в изхода, релативна спрямо последната
            премината граница на табулатор */

int spaces; /* текущ пореден брой шпации */

void eval(char c);
void flush();
int tab2spaces(int pos);

main()
{
  int c; /* текущият символ */

  spaces = 0; /* все още не сме срещнали никакви шпации */
  pos = 0; /* представяме си, че сме в начална позиция */

  /* Взимаме всеи знак от входа и най-безотговорно го изпращаме към
     функцията eval.  Тя ще му мисли какво да го прави. */
  while ((c = getchar()) != EOF)
    eval(c);

  /* Ако имаме нещо събрано в "буфера" spaces, трябва да го изпразним. */
  flush();

  return 0;
}

/* eval: интерпретира символ и го извежда на изхода. */
void eval(char c)
{
  int inc;
  inc = FALSE;

  /* Рендваме насъбралите се в буфера шпации при всяко срещане на
     редовен знек (т.н. не шпация или табулатор). */
  if ((c != SPACE) && (c != '\t'))
    flush();

  if (c == '\n') {
    /* реинициализираме състоянието си при нов ред */
    pos = 0;
    putchar(c);
  }
  else if (c == '\t') {
    /* трансформация на табулатора */
    tab2spaces(pos);
  }
  else if (c == SPACE) {
    /* шпацията "гълтаме" в буфера */
    ++spaces;
    inc = TRUE;
  }
  else {
    putchar(c);
    inc = TRUE;
  }

  if (inc == TRUE)
    ++pos;

  /* При достигането на границата на табулатор, изпразваме буфера и
     рестартираме брояча на позициите. */
  if (pos == N) {
    flush();
    pos = 0;
  }

}

/* flush: извежда съдържанието на буфера за шпации и го изчиства */
void flush()
{
  int i;

  if (spaces == 0) return;

  if (pos == N)
    putchar('\t');
  else
    for (i = 0; i < spaces; ++i)
      putchar(SPACE);

  spaces = 0;
}

/* tab2spaces: извежда необходимия брой шпации при срещнат табулатор
   на дадената позиция pos; връща броя им. */
int tab2spaces(int pos)
{
  int spaces;
  int i;

  spaces = N - (pos % N);
  for (i = 0; i < spaces; ++i)
    eval(SPACE);
  return spaces;
}
