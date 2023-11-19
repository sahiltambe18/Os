
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdio.h>

sem_t reader , writer;
int count = 0;
void* writerFunc(){
    sem_wait(&writer);
        printf("writer\n")
    sem_post(&writer);
}

void* readerFunc(){
    sem_wait(&reader);
    count++;
    if (count==1)
    {
        sem_wait(&writer);
    }
    sem_post(&reader);
    printf("reader\n");
    sem_wait(&reader);
      count--;
      if (count==0)
      {
        sem_post(&writer);
      }
      
    sem_post(&reader);

}



void main(){
    sem_init (&reader , 0 , 1);
    sem_init (&writer , 0 , 1);

    p_thread wth[3] , rth[3];

    pthread_create(&wth[0],NULL,writerFunc,NULL);
    pthread_create(&wth[2],NULL,writerFunc,NULL);
    pthread_create(&wth[0],NULL,readerFunc,NULL);
    pthread_create(&wth[1],NULL,readerFunc,NULL);
    pthread_create(&wth[1],NULL,writerFunc,NULL);
    pthread_create(&wth[2],NULL,readerFunc,NULL);
    sleep(5);   
}