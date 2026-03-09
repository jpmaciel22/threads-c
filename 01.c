#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* routine()
{
printf("Test from threads\n"); 
sleep(3);
printf("Ending thread\n");
}

int main() {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0){
        printf("ERROR\n");
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0){
        printf("ERROR 2\n");
    }
    pthread_join(t1, NULL); // o segundo parametro é meio q a var pra guardar o retorno mas a gnt n retorna nda... so um printzao ! o join é pra declarar q tem q esperar ate o fim da execucao...
    pthread_join(t2, NULL);
    return 0;
}