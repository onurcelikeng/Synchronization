#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<semaphore.h>
#include "helper.h"
#include "groom.h"
#include "bride.h"
#include "registrar.h"

pthread_t registrarThread[2];
pthread_t processThread;

void SemaphoreInitialize();
void Process();

int main()
{
    SemaphoreInitialize(); //initialize of all semaphore

    pthread_create(&registrarThread[0], NULL, (void *)RegistrarProcess, (void *)0);
    pthread_create(&registrarThread[1], NULL, (void *)RegistrarProcess, (void *)1);
    pthread_create(&processThread, NULL, (void *)Process, NULL);

    //condition of generate bride
    char input = '+';
    while(true)
    {
        input = getchar();
        if(input != '+')
        {
            Statistics();
            return 0;
        } 
    }

    return 0;
}

void SemaphoreInitialize()
{
    sem_init(&mutex, 0, 1);
    sem_init(&bride, 0, 0);
    sem_init(&groom, 0, 0);
    sem_init(&registrar, 0, 2);
}

void Process()
{
    while(true)
    {
        int data = randomNumber();// between 1 and 5

        if(data < 3)//control for creating a person
        {
            if(data % 3 == 1) //condition of generate bride
            {
		        pthread_t brideThread;
                pthread_create(&brideThread, NULL, (void *)BrideProcess, NULL);
            }

            else if(data % 3 == 2) //condition of generate groom
            {
		        pthread_t groomThread;
                pthread_create(&groomThread, NULL, (void *)GroomProcess, NULL);
            }
        }
        
        sleep(1);
    }
}
