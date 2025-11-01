#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void * myturn(void * p);
void yourturn();

int main(int argc, char const *argv[])
{
    pthread_t thread1;
    int t1 = pthread_create(&thread1, NULL, myturn, NULL);
    yourturn();

    // Se a função yourturn terminar antes de myturn, o programa vai terminar e a myturn pode acabar não terminando a tarefa dela.
    // para resolver esse problema, podemos usar pthread_join(void * (*funcao)(void *), void ** reval) que "junta a thread ao thread principal"
    // na verdade, pthread_join vai retornar assim que a thread terminar.

    pthread_join(thread1, NULL);

    return 0;
}

void * myturn(void * p)
{
    int c = 0;

    while (c < 20)
    {
        sleep(1);
        printf("My turn.\n%d secs\n", c);
        c++;
    }

    return NULL;    
}

void yourturn()
{
    int c = 0;

    while (c < 10)
    {
        sleep(1);
        printf("Your turn. \n%d secs\n", c);
        c++;
    }  
}