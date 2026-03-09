#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

void* roll_dice()
{
    int* value = malloc(sizeof(int));
    *value = (rand() % 6) + 1;
    return (void*) value;
}


int main()
{
 int* result;
 srand(time(NULL));
 pthread_t th;
 pthread_create(&th, NULL, &roll_dice, NULL );
 pthread_join(th, (void**) &result); // aqui basicamente a gnt aponta pro endereco da memoria de result, acha guardado la o endereco d memoria do "value", dai aponta pro valor desse endereco d memoria e ai qnd chamarmos o valor achamos o rsultado de roll_dice
 printf("%d\n", *result);
 free(result);
 return 0;
}