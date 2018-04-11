// PROGRAMA p01.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 50000

int i;

void * thrfunc(void * arg)
{
  int * num = malloc(sizeof(int));
  *num = 0;
  fprintf(stderr, "Starting thread %s\n", (char *) arg);
  while(i>0) {
    fprintf(stderr,"%d:%s",i,(char*)arg);
    i--;
    (*num)++;
  }
  return ((void*)num);
}
int main()
{
  pthread_t ta, tb;
  void * num1;
  void * num2;
  char * a = "a";
  char * b = "b";
  i = NUMITER;
  pthread_create(&ta, NULL, thrfunc, a);
  pthread_create(&tb, NULL, thrfunc, b);
  pthread_join(ta, (void*)&num1);
  pthread_join(tb, (void*)&num2);
  printf("\nnumber of a = %d\n",*((int*)num1));
  printf("number of b = %d\n",*((int*)num2));
  return 0;
}
