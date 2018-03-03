#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 20

int main(void)
{
 int fd2;
 char name[NAME_SIZE];
 fd2 = open("names.txt", O_WRONLY | O_CREAT, 0644);
 if (fd2 == -1) {
  return 2;
 }
 printf("Names and Grades:\n");
 while (fgets(name,NAME_SIZE,stdin) != NULL){
  if (write(fd2, name, strlen(name)) <= 0) {
   close(fd2);
   return 4;
  }
}
  close(fd2);
  return 0;
}
