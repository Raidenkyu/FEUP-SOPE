#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 256
#define READ 0
#define WRITE 1


int main(int argc, char * argv[]){
  if(argc != 2){
    perror("Invalid number of arguments\n");
    return 1;
  }
  int fd[2];
  char num[MAX];
  FILE* file;
  file = fopen(argv[1],"w");
  while((n = read()))


  return 0;
}
