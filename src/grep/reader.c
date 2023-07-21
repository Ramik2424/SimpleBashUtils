#include "grep.h"
void reader(flags *Options, char *pattern, char *file) {
  char str[9999];
  int counter = 0;
  int counterString = 0;
  regex_t reegex;
  regcomp(&reegex, pattern, REG_EXTENDED);
  FILE *f;
  int optSearch;

  if ((f = fopen(file, "r")) != NULL) {
    while ((fgets(str, 9999, f)) != NULL) {
      counterString++;
      optSearch = regexec(&reegex, str, 0, NULL, 0);

      if (Options->f) {
        FILE *pattern_file = fopen(Options->pattern_file_name, "r");
        if (pattern_file == NULL) {
          fprintf(stderr, "Ошибка открытия файла: %s\n", pattern);
          exit(1);
        }
        int leght_pattern_file = 1000;
        char pattern_line[leght_pattern_file];
        while (fgets(pattern_line, leght_pattern_file, pattern_file) != NULL) {
          pattern_line[strcspn(pattern_line, "\n")] = '\0';
          regex_t temp_regex;
          regcomp(&temp_regex, pattern_line, REG_EXTENDED);
          optSearch = regexec(&temp_regex, str, 0, NULL, 0);

          if (optSearch == 0) {
            break;
          }

          regfree(&temp_regex);
        }

        fclose(pattern_file);

        if (optSearch != 0) {
          continue;
        }
      }
      if (Options->i) {
        regfree(&reegex);
        regcomp(&reegex, pattern, REG_ICASE);
        optSearch = regexec(&reegex, str, 0, NULL, 0);
      }

      if (Options->v) {
        optSearch = !optSearch;
      }

      if (Options->h) {
        Options->notOneFile = 0;
      }

      if (optSearch == 0) {
        counter++;
        if (str[strlen(str) - 1] != '\n') {
          int end = strlen(str);
          str[end] = '\n';
          str[end + 1] = '\0';
        }

        if (Options->c != 1 && Options->l != 1) {
          if (Options->notOneFile && Options->n) {
            printf("%s:%d:%s", file, counterString, str);
          } else if (Options->notOneFile && !Options->n) {
            printf("%s:%s", file, str);
          } else if (!Options->notOneFile && Options->n) {
            printf("%d:%s", counterString, str);
          } else {
            printf("%s", str);
          }
        }
      }
    }

    if (Options->c && !Options->l) {
      if (Options->notOneFile) {
        printf("%s:%d\n", file, counter);
      } else {
        printf("%d\n", counter);
      }
    }

    if (Options->c && Options->l) {
      if (counter == 0) {
        counter = 0;
      } else {
        counter = 1;
      }
      if (Options->notOneFile) {
        printf("%s:%d\n", file, counter);
      } else {
        printf("%d\n", counter);
      }
    }

    if (Options->l && counter != 0) {
      counter = 1;
      printf("%s\n", file);
    }
    fclose(f);
  }

  regfree(&reegex);
}