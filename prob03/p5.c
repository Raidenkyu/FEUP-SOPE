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
    pid = fork();
    switch(pid){
      case -1:
       perror("fork");
      break;
      case 0: //filho
       write(STDOUT_FILENO,"friends!\n",10);
      break;
      default:
        write(STDOUT_FILENO,"my ",3);

    }

    break;
    default: //pai
      write(STDOUT_FILENO,"Hello ",6);
  }
  return 0;
}
