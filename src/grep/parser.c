#include "grep.h"
int parser(int argc, char *argv[], flags *Options) {
  int opt;
  int needOpt = 1;
  int index = 0;
  const struct option long_options[] = {{NULL, 0, NULL, 0}};
  while ((opt = getopt_long(argc, argv, "ef:ivclnhsfo", long_options,
                            &index)) != -1) {
    Options->e = 1;
    needOpt = 0;
    switch (opt) {
      case 'i': {
        Options->i = 1;
        break;
      };

      case 'e': {
        Options->e = 1;
        Options->f = 0;
        break;
      };

      case 'h': {
        Options->h = 1;
        break;
      }

      case 'v': {
        Options->v = 1;
        break;
      }

      case 'c': {
        Options->c = 1;
        break;
      }

      case 'l': {
        Options->l = 1;
        break;
      }

      case 'n': {
        Options->n = 1;
        break;
      }

      case 'f': {
        Options->e = 0;
        Options->f = 1;
        Options->pattern_file_name = optarg;
        break;
      }

      case 's': {
        Options->s = 1;
        opterr = 0;
        break;
      }

      case 'o': {
        Options->o = 1;
        break;
      }
      default: { fprintf(stderr, "No %s file in derectory.\n", argv[optind]); }
    }
  }

  if (needOpt == 1) {
    Options->e = 1;
  }

  if (optind + 2 < argc) {
    Options->notOneFile = 1;
  }
  return 1;
}