#include "grep.h"

int main(int argc, char *argv[]) {
  flags Options = {0};
  if (parser(argc, argv, &Options) == 1) {
    char *pattern = argv[optind];
    while (optind < argc) {
      reader(&Options, pattern, argv[optind]);
      optind++;
    }
  }
}
