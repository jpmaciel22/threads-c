#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* routine()
{
    printf("Process id of this thread: %d \n", getpid());
}

int main()
{
    int pid = fork(); // isso cria um PROCESSO filho que roda concorrentemente ao pai.
    if ( pid == -1 ){
        return 1;
    }
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0; 
    // portanto printaremos a rotina 4 vezes, já que, o processo filho tb cria 2 threads.
}