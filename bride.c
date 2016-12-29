#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "helper.h"

void BrideProcess()
{
    sem_wait(&mutex);

    sizeofBride++;
    printf("Gelin oluştu, gelin sayısı : %d\n", sizeofBride);

    sem_post(&mutex);
    sem_post(&bride);
    sem_wait(&registrar);
}