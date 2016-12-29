#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <semaphore.h>
#include <sys/syscall.h>
#include "helper.h"

void RegistrarProcess(void *arg)
{
    while(true)
    {
        sem_wait(&groom);
        sem_wait(&bride);

		pid_t id = syscall(SYS_gettid);

        sleep(randomNumber());

        sem_wait(&mutex);

        sizeofGroom--; //Decrement(sizeofGroom);
        sizeofBride--; //Decrement(sizeofBride);
        sizeofCouple++; //Increment(sizeofCouple);

        printf("Evli sayısı : %d , Memur id: %ld\n", sizeofCouple, id);
        
        sem_post(&mutex);
        sem_post(&registrar);
    }
}