#include "cat.h"

int main(int argc, char *argv[]) {
  flags options = {0};
  if (cat_parser(argc, argv, &options) == 1) {
    while (optind < argc) {
      cat_reader(argv, &options);
      optind++;
    }
  }
  return 0;
}