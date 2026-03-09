#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

int x = 0;
pthread_mutex_t mutex;
void* routine()
{
  for(int i = 0; i < 10000000; i++){
      pthread_mutex_lock(&mutex);
      x++;
      pthread_mutex_unlock(&mutex);
   // read x
   // add 1 x
   // write x
  }
}

int len(void* array){
    return sizeof(array)/sizeof(array[0]);
}


int main()
{
    pthread_t th[4];
    int array[] = {1,2,3,4};
    printf("LENGTH DO ARRAY: %d\n", LEN(array));
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < 4; i++)
     pthread_create(&th[i], NULL, &routine, NULL);
    for(int i = 0; i < 4;i++)
     pthread_join(th[i], NULL);
    pthread_mutex_destroy(&mutex);
    printf("number X : %d\n", x);
    return 0; 
}