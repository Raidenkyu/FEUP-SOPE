// PROGRAMA p02a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo){
  printf("Entering SIGINT handler ...\n");
  sleep(10);
  printf("Exiting SIGINT handler ...\n");
}

void sigterm_handler(int signo){
  printf("Entering SIGTERM handler ...\n");
  sleep(10);
  printf("Exiting SIGTERM handler ...\n");
}

int main(void)
{
  printf("PID: %d\n",getpid());

  struct sigaction action,a2;
  action.sa_handler = sigint_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;

  a2.sa_handler = sigint_handler;
  sigemptyset(&a2.sa_mask);
  a2.sa_flags = 0;

  if (sigaction(SIGINT,&action,NULL) < 0){
    fprintf(stderr,"Unable to install SIGINT handler\n");
    exit(1);
  }
  
  if (sigaction(SIGTERM,&a2,NULL) < 0){
    fprintf(stderr,"Unable to install SIGINT handler\n");
    exit(1);
  }

  printf("Try me with CTRL-C ...\n");
  while(1) pause();
  exit(0);
}
