#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void* arg)
{
    int index = *(int*)arg;
    int* sum = malloc(sizeof(int));
    *sum = 0;
    for( int i = index; i < (index + 5) ; i++){
        *sum += primes[i];
    }
    printf("%d : ", *sum);
    return (void*) sum;
    free(arg);
}

int main() {
    int* result;
    int sumG = 0;
    pthread_t th[2];
    for(int i = 0; i < 2; i++){
    int* a = malloc(sizeof(int));
    *a = i * 5;
     pthread_create(&th[i], NULL, &routine, a);
    }
    for(int i = 0; i < 2; i++){
     pthread_join(th[i], (void**) &result);
     sumG += *result;
     free(result);
    }
    printf("sum : %d", sumG);
    return 0;
}