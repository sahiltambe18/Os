#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
  int fd1;
  char arr1[80],arr2[80],buffer[100];
  
  char *myfifo="myfifo";
  mkfifo(myfifo,0666);
  
  while(1){
  
    fd1=open(myfifo,O_RDONLY);
    read(fd1,arr1,80);
    
    close(fd1);
    printf("%s",arr1);
    int i=0,wordCount=0,lineCount=0,charCount=0;
    
    
    while (i < strlen(arr1)) {
            if (arr1[i] == ' ') {
                wordCount++;
                charCount++;
            } else if (arr1[i] == '\n') {
                wordCount++;
                lineCount++;
            } else {
                charCount++;
            }
            i++;
        }
  
    FILE *countfile=fopen("count.txt","w");
    if(countfile!=NULL){
      fprintf(countfile,"Char count : %d\n",charCount);
      fprintf(countfile,"word count : %d\n",wordCount);
      fprintf(countfile,"line count : %d\n",lineCount);
      fclose(countfile);
    }else{
      perror("Enable to open count.txt.");
    }
    
    fd1=open(myfifo,O_WRONLY);
    write(fd1,arr1,strlen(arr1)+1);
    close(fd1);
  }
  return 0;
}

/*

------------------OUTPUT---------------


sahil@sahil:~$ gcc fifo2_p.c 
sahil@sahil:~$ ./a.out
sahil Pensalwar
sahil
sahil
^C
sahil@sahil:~$ 


*/
