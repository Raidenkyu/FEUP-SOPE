#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 30
#define READ 0
#define WRITE 1


int main(int argc, char *argv[]){

  int fd[2];
  pid_t pid;
  char num[MAX];
  int n;

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
   }

   pid = fork();

  if(pid > 0){
    close(fd[READ]);
    write(STDOUT_FILENO,"Indique o primeiro valor: ",26);
    n = read(STDIN_FILENO,num,MAX);
    write(fd[WRITE],num,n);
    write(STDOUT_FILENO,"\nIndique o segundo valor: ",26);
    n = read(STDIN_FILENO,num,MAX);
    write(fd[WRITE],num,n);
  }
  else{
    close(fd[WRITE]);
    int num1,num2;
    n = read(fd[READ],num,MAX);
    num1 = atoi(num);
    n = read(fd[READ],num,MAX);
    num2 = atoi(num);

    printf("\nSoma: %d\n",num1+num2);
    printf("\nDiferença: %d\n",num1-num2);
    printf("\nMultiplicação: %d\n",num1*num2);
    if(num2 == 0){
      printf("\nNão se pode dividir um número por zero\n");
    }
    else{
      printf("\nDivisão: %f\n",(float)num1/(float)num2);
    }
  }
  return 0;
}
