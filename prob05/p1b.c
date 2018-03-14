#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 30
#define READ 0
#define WRITE 1


typedef struct {
  int num1;
  int num2;
} operands;


int main(int argc, char *argv[]){

  int fd[2];
  pid_t pid;
  char num[MAX];
  operands values;

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
   }

   pid = fork();

  if(pid > 0){
    close(fd[READ]);
    write(STDOUT_FILENO,"Indique o primeiro valor: ",26);
    read(STDIN_FILENO,num,MAX);
    values.num1 = atoi(num);
    write(STDOUT_FILENO,"\nIndique o segundo valor: ",26);
    read(STDIN_FILENO,num,MAX);
    values.num2 = atoi(num);
    write(fd[WRITE],&values,sizeof(operands));
  }
  else{
    close(fd[WRITE]);
    read(fd[READ],&values,MAX);


    printf("\nSoma: %d\n",values.num1+values.num2);
    printf("\nDiferença: %d\n",values.num1-values.num2);
    printf("\nMultiplicação: %d\n",values.num1*values.num2);
    if(values.num2 == 0){
      printf("\nNão se pode dividir um número por zero\n");
    }
    else{
      printf("\nDivisão: %f\n",(float)values.num1/(float)values.num2);
    }
  }
  return 0;
}
