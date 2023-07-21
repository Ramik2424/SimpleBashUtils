#include "cat.h"
void cat_reader(char **argv, flags *options) {
  FILE *file;
  if ((file = fopen(argv[optind], "r")) != NULL) {
    int str_count = 0;
    int count = 1;
    char cur;
    char con = '\n';
    while ((cur = fgetc(file)) != EOF) {
      if (((options->b) && (cur != '\n') && (con == '\n')) ||
          ((!options->b) && (options->n) && (con == '\n'))) {
        printf("%6d\t", count++);
      }
      if (options->v && !(cur >= 32 && cur < 127) && cur != '\n' &&
          cur != '\t') {
        if (cur == 127) {
          printf("^");
          cur -= 64;
        } else if (cur < 32 && cur >= 0) {
          printf("^");
          cur += 64;
        }
      }
      if ((options->t && cur == '\t')) {
        printf("^");
        cur = 'I';
      }
      if ((options->e) && (cur == '\n')) {
        printf("$");
      }
      if (((options->s) && (cur == '\n') && (con == '\n'))) {
        str_count++;
        if (str_count > 1) {
          continue;
        }
      }
      printf("%c", cur);
      if (con == '\n' && cur != '\n') {
        str_count = 0;
      }
      con = cur;
    }
    fclose(file);
  } else {
    printf("no such file in directory.");
  }
}