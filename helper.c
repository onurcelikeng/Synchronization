#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int sizeofGroom;
int sizeofBride;
int sizeofCouple;
sem_t registrar;
sem_t mutex;
sem_t groom;
sem_t bride;

int randomNumber()
{
    srand(time(NULL));
    int value = rand() % 5 + 1; //between 1 and 5

    return value;
}

void Statistics()
{
    printf("Bekar gelin sayısı : %d\n", sizeofBride);
    printf("Bekar damat sayısı : %d\n", sizeofGroom);
    printf("Evli çift sayısı : %d\n", sizeofCouple);
}