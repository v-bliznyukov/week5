#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* Message(void *thread){
printf("Hello, thread number: %d\n",(long)thread);
return 0;
}
//program with 'random' order of message appear
int main (){
  //create the only thread that would be executed at a time
  pthread_t id;
int n;
scanf("%d", &n);
int r;
int i;
for( i=0; i<n; i++){
//create a thread
pthread_create(&id, NULL, Message,(void*)i);
printf("Thread was created %d\n",i);
//terminate thread after message
pthread_join(id, NULL);
printf("finised with %d\n", i);
}
}