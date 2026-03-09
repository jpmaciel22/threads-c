#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

 int x = 2;

void* routine()
{
    x++;
    printf("Value of X: %d\n", x);
}

void* routine2()
{
    printf("Value of X: %d\n", x); // aqui tb vai printar 3 pq ele acessou logo dps q a 
    // outra thread somou...
}

int main()
{
    int pid = fork(); // isso cria um PROCESSO filho que roda concorrentemente ao pai.
    if ( pid == -1 ){
        return 1;
    }
    if(pid == 0){ // se for processo filho
        x++;
    }
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0; 
    // portanto printaremos a rotina 4 vezes, já que, o processo filho tb cria 2 threads.
}