#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int time();

void Readfile(char const *filname) {
  srand(time(NULL));

  FILE *f;
  char c;
  int r = rand() % 6;
  char *colors[6] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};

  f = fopen(filname, "rt");

  if (f == NULL) {
    printf("Arquivo inválido!\n");
    return;
  }

  while ((c = fgetc(f)) != EOF) {
    r = rand() % 6;
    printf("%s%c%s", colors[r], c, RESET);
  }
  printf("\n");
  fclose(f);
}

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    printf("Faltam argumentos!\n");
    return 1;
  }

  Readfile(argv[1]);
  return 0;
}
