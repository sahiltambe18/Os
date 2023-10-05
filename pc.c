#include<stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t  e , f , s;
int buffer[5] , in = 0 , out = 0;
int data[] = {11,12,13,14,15};
void* prod(void * arg){
	sem_wait(&e);
	//critical section
	  sem_wait(&s);
		buffer[in] = data[in];
		printf("producer %d \n",buffer[in]);
		in = (in+1)%5;
  	  sem_post(&s);
  	sem_post(&f);
  	
}

void* consumer(void *arg){
	int val , c;
	do{
		sem_wait(&f);
		///critical 
			sem_wait(&s);
				printf("consumer %d \n",buffer[out]);
				c = buffer[out];
				out = (out+1)%5;	
			sem_post(&s);
		sem_post(&e);
		sem_getvalue(&e , &val);
		
	}while(val!=5);
}

void main(){
	sem_init(&s , 0 , 1);
	sem_init(&e , 0 , 5);
	sem_init(&f , 0 , 0);
	
	pthread_t tp[5], tc;
	
	for(int i=0;i<5;i++){
 		pthread_create(&tp[i], NULL, prod, NULL);
 	}
        pthread_create(&tc, NULL, consumer, NULL);
        
        for(int i=0;i<5;i++){
		pthread_join(tp[i], NULL);
        }
        pthread_join(tc, NULL);
	
}
