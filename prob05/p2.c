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

typedef struct {
  int sum;
  int sub;
  int mul;
  float div;
  int integer;
} results;


int main(void){

  int fd[2];
  pid_t pid;
  char num[MAX];
  operands values;
  results r;

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
   }

   pid = fork();

  if(pid > 0){
    write(STDOUT_FILENO,"Indique o primeiro valor: ",26);
    read(STDIN_FILENO,num,MAX);
    values.num1 = atoi(num);
    write(STDOUT_FILENO,"\nIndique o segundo valor: ",26);
    read(STDIN_FILENO,num,MAX);
    values.num2 = atoi(num);
    write(fd[WRITE],&values,sizeof(operands));
    wait(NULL);
    read(fd[READ],&r,sizeof(results));

    printf("\nSoma: %d\n",r.sum);
    printf("\nDiferença: %d\n",r.sub);
    printf("\nMultiplicação: %d\n",r.mul);
    if(r.integer == -1){
      printf("\nNão se pode dividir um número por zero\n");
    }
    else if(r.integer == 0){
      printf("\nDivisão: %f\n",r.div);
    }
    else{
      printf("\nDivisão: %d\n",(int)r.div);
    }
  }
  else{
    read(fd[READ],&values,sizeof(operands));
    r.sum = values.num1+values.num2;
    r.sub = values.num1-values.num2;
    r.mul = values.num1*values.num2;
    if(values.num2 == 0){
      r.integer = -1;
    }
    else if(values.num1 % values.num2 == 0){
      r.integer = 1;
      r.div = (float)values.num1/(float)values.num2;
    }
    else{
      r.integer = 0;
      r.div = (float)values.num1/(float)values.num2;
    }
    write(fd[WRITE],&r, sizeof(results));
  }
  return 0;
}
