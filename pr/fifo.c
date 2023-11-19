#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

  int fd;
  char *myfifo="myfifo";
  mkfifo(myfifo,0666);
  
  char arr1[80],arr2[80],buffer[100];
  
  while(1){
  
  int i = 0, wordCount = 0, lineCount = 0, charCount = 0;

  
    fd=open(myfifo,O_WRONLY);
    printf("Enter data.");
    fgets(arr2,80,stdin);
    write(fd,arr2,strlen(arr2)+1);
    close(fd);
    
    fd=open(myfifo,O_RDONLY);
    read(fd,arr1,sizeof(arr1));
    
    close(fd);
    
    
    
    
    FILE *countfile=fopen("count.txt","r");
    if(countfile!=NULL){
      fread(buffer,sizeof(buffer),1,countfile);
      fclose(countfile);
      
      printf("Contents of buffer :%s",buffer);
      
    }else{
      perror("Unable to open count.txt");
    }
    
  
  }
    return 0;
}

/*

------------------------------OUTPUT-----------------------
sahil@sahil:~$ gcc fifo1_p.c -o b.out
sahil@sahil:~$ ./b.out
Enter data.sahil Pensalwar
Contents of buffer :Char count : 17
word count : 2
line count : 1
Enter data.sahil
Contents of buffer :Char count : 7
word count : 1
line count : 1

Enter data.^C
sahil@sahil:~$ ^C
sahil@sahil:~$ 





*/