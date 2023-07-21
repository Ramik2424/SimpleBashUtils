#include "cat.h"
int cat_parser(int argc, char *argv[], flags *options) {
  const struct option long_options[] = {
      {"--number-nonblank", 0, NULL, 'b'},
      {"--show-nonprinting-ends", 0, NULL, 'e'},
      {"--number", 0, NULL, 'n'},
      {"--squeeze-blank", 0, NULL, 's'},
      {NULL, 0, NULL, 0}};
  int opt;
  int index = 0;
  while ((opt = getopt_long(argc, argv, "+benstvET", long_options, &index)) !=
         -1) {
    switch (opt) {
      case 'b': {
        options->b = 1;
        break;
      };
      case 'E': {
        options->e = 1;
        break;
      };
      case 'T': {
        options->t = 1;
        break;
      };
      case 'e': {
        options->e = 1;
        options->v = 1;
        break;
      };
      case 'n': {
        options->n = 1;
        break;
      };
      case 's': {
        options->s = 1;
        break;
      };
      case 't': {
        options->t = 1;
        options->v = 1;
        break;
      };
      case 'v': {
        options->v = 1;
        break;
      };
      default:
        fprintf(stderr, "No %s file in derectory.\n", argv[optind]);
    }
  }
  return 1;
}