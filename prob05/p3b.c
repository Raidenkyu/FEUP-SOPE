#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX 256
#define READ 0
#define WRITE 1


int main(int argc, char * argv[]){
  if(argc != 2){
    perror("Invalid number of arguments\n");
    return 1;
  }

  int fd[2];
  int file;
  pid_t pid;

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
   }

   file = open(argv[1],O_RDONLY,0644);

   if(file == -1){
     perror("File not found");
     return 0;
   }

   pid = fork();

  if(pid > 0){
    pid = fork();
    if(pid > 0){
      wait(NULL);
      close(fd[READ]);
    }
    else {
    close(fd[READ]);
    dup2(file,STDIN_FILENO);
    dup2(fd[WRITE],STDOUT_FILENO);
    execlp("cat","cat",NULL);
  }
  close(fd[WRITE]);
}
  else{
    close(fd[WRITE]);
    dup2(fd[READ],STDIN_FILENO);
    execlp("sort","sort",NULL);

  }

  return 0;
}
