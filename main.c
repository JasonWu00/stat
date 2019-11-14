#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  printf("Main.c will be obtaining metadata on the makefile.\n");

  struct stat makefileStats;

  stat("makefile", &makefileStats);

  printf("Displaying metadata on the makefile below.\n--------------------\n");
  printf("The makefile is %li bytes large.\n", makefileStats.st_size);
  printf("The makefile's mode: %o\n", makefileStats.st_mode);
  const time_t time = makefileStats.st_atime;
  printf("Makefile last accessed: %s\n", ctime(&time));
}
