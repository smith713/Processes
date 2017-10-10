// Write a program that opens the text.txt  file (with the `open()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `open()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    fp = fopen("text.txt", "w");

    int ret = fork();
    if(ret < 0) {
      printf("Fork child creation failed");
      exit(1);
    } else if (ret == 0) {
      printf("Child process\n");
      char child_str[] = "Reporting from child\n";
      fwrite(child_str, 1, sizeof(child_str), fp);
    } else {
      printf("Parent process\n");
      char parent_str[] = "Reporting from parent\n";
      fwrite(parent_str, 1, sizeof(parent_str), fp);
    }
     
    fclose(fp);
    return 0;
}
