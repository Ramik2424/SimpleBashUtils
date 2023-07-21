#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct Options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int E;
  int T;
} flags;

void cat_reader(char **argv, flags *options);
int cat_parser(int argc, char *argv[], flags *options);