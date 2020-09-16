#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* Message(void *thread){
printf("Hello, thread number: %d\n",(long)thread);
pthread_exit(NULL);
}
//program with 'random' order of message appear
int main (){
int n;
scanf("%d", &n);
pthread_t threads[n];
int r;
int i;
for( i=0; i<n; i++){

pthread_create(&threads[i], NULL, Message,(void*)i);
printf("Thread was created %d\n",i);
}
pthread_exit(NULL);
}