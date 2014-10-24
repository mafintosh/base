#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// the main use for this is to avoid being PID=1

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s [program] [arguments..]\n", argv[0]);
    exit(1);
  }

  char **argvc = argv + 1;
  int status = -1;
  pid_t cpid = vfork();

  if (cpid > 0) wait(&status);
  else execvp(argvc[0], argvc);

  return status;
}