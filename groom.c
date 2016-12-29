#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "helper.h"

void GroomProcess()
{
    sem_wait(&mutex);

    sizeofGroom++;
    printf("Damat oluştu, damat sayısı : %d\n", sizeofGroom);
    
    sem_post(&mutex);
    sem_post(&groom);
    sem_wait(&registrar);
}