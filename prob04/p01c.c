// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

  int i = 1;

void sigterm_handler(int signo){
  printf("In SIGINT handler ...\n");
  exit(0);
}

void sigusr1_handler(int signo){
  printf("Increasing ...\n");
  i = 1;
}

void sigusr2_handler(int signo){
  printf("Decreasing ...\n");
  i = -1;
}

int main(void){
  struct sigaction s1,s2,s3;
  int v = 0;
  s1.sa_handler = sigint_handler;
  sigemptyset(&s1.sa_mask);
  s1.sa_flags = 0;
  s2.sa_handler = sigusr1_handler;
  sigemptyset(&s2.sa_mask);
  s2.sa_flags = 0;
  if (sigaction(SIGTERM,&s1,NULL) < 0){
    fprintf(stderr,"Unable to install SIGTERM handler\n");
    exit(1);
  }

  if (sigaction(SIGUSR1,&s2,NULL) < 0){
    fprintf(stderr,"Unable to install SIGUSR1 handler\n");
    exit(1);
  }
  printf("PID: %d\n",getpid());
  printf("Sleeping for 30 seconds ...\n");
  sleep('s');
  sleep(30);
  printf("Waking up ...\n");
exit(0);
}
