// PROGRAMA p6.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
  pid_t pid, w;
  int i, wstatus;
  printf("I'm process %d. My parent is %d.\n", getpid(),getppid());
  for (i=1; i<=3; i++) {
    pid = fork();
    if ( pid < 0) {
      printf("fork error");
      exit(1);
    }
    else if (pid == 0) {
      printf("I'm process %d. My parent is %d. I'm going to work for 1 second ...\n",getpid(),getppid());
      sleep(1); // simulando o trabalho do filho
      printf("I'm process %d. My parent is %d. I finished my work\n", getpid(),getppid());
      exit(0);
    }
    else
    // a eliminar na alinea c)
    // simulando o trabalho do pai
    do {
        w = waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
        if (w == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        printf("father working ...\n");
    } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));

  }
  exit(0);
}
