//consumer producer problem using wakeup/sleep routines
//done by using global variables
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//number of possible products stored
#define BUFFER_SIZE 1000
//initialize number of produced product
int itemCount=0;

//producer function
void* producerf(void *arg){

 while(1){
   //"sleep" routine if cannot make any more product
  while(itemCount==BUFFER_SIZE){}
  //else "wake up" and print the current number of available products
   printf("Producer produces%d \n",itemCount);
   //if can make more
  if(itemCount<BUFFER_SIZE){
   //increase number of products
   itemCount++;
  }
 }
}
//consumer function
void* consumerf(void *arg){
 
 while(1){
   // "sleep" routine for consumer if nothing can be taken
  while(itemCount==0){}
  //print the current number of product available for consumer
   printf("Consumer takes%d \n",itemCount);
   //if some product available
  if(itemCount>0){
    //decrease the number of products
   itemCount--;
  }
 }
}
//the race condition appeares when consumer and producer come to action after one another. Firts ouput of itemCount of produces/consumer is differernt from reality because the thread uses the old value (before it was blocked by condition)

int main(){
pthread_t producer, consumer;
 pthread_create(&producer,NULL,&producerf,NULL);
 pthread_create(&consumer,NULL,&consumerf,NULL);
 //to guarantee the producer thread is terminated
 pthread_join(producer,NULL);
 return 0;
}
//Source wikipedia https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem