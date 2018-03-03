#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main(void) {
  pid_t pid;
  pid=fork();
  switch (pid) {
    case -1:
    perror("fork");
    break;
    case 0: //filho
      write(STDOUT_FILENO,"Hello",5);
    break;
    default: //pai
      write(STDOUT_FILENO,"World !\n",8);
  }
  return 0;
}
