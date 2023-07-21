#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct Options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int notOneFile;
  char *pattern_file_name;
} flags;
int parser(int argc, char *argv[], flags *Options);
void reader(flags *Options, char *pattern, char *file);