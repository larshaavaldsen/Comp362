/*
    Lars Haavaldsen
    COMP 362
*/
#include <asm-generic/errno-base.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define SLEEP_TIME ( (rand() % 5 + 1) * 1000)

enum { THINKING, HUNGRY, EATING} *state; // state array

void *philosopher(void *id);

pthread_cond_t *self; // self condition array
pthread_mutex_t monMutex = PTHREAD_MUTEX_INITIALIZER; // monitor mutex

int numOfSeats, numOfTurns;

// functions for pickup, put down, etc

// test and signal neighbor, from psudeo code
void test(int i) {
    if ((state[(i +  (numOfSeats - 1)) % numOfSeats] != EATING) && (state[i] == HUNGRY) && (state[(i + 1) % numOfSeats] != EATING) ) {
        state[i] = EATING ;
        pthread_cond_signal(&self[i]);
      }
}

// pickup chopstick
void pickup(int i) {
    pthread_mutex_lock(&monMutex);
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING) {
        printf("thread %d waiting", i);
        pthread_cond_wait(&self[i], &monMutex);
    }
    pthread_mutex_unlock(&monMutex);

}

// put down
void putdown(int i) { 
    pthread_mutex_lock(&monMutex);
    state[i] = THINKING;
      // test left and right neighbors
      test((i + (numOfSeats - 1)) % numOfSeats);
      test((i + 1) % numOfSeats);
    pthread_mutex_unlock(&monMutex);

}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: philosophers <number of seats> <number of turns>\n");
        return 1;
    }

    // get seats and turns
    numOfSeats = strtod(argv[1], NULL);
    numOfTurns = strtod(argv[2], NULL);

    // init code stuffs
    state = malloc(numOfSeats * sizeof(int)); // malloc state array
    self = calloc(numOfSeats, sizeof(pthread_cond_t)); // calloc conditionals 

    // set all states to thinking
    for (int i = 0; i < numOfSeats; i++) {
         state[i] = THINKING;
   }

    // set the see for random number generator
    srand(time(NULL));

    // pthread attrs
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    printf("Start a dinner for %d diners\n", numOfSeats);

    pthread_t philosopher_tid[numOfSeats];

    long i;
    for (i = 0; i < numOfSeats; i++)
        pthread_cond_init(self + i, NULL);

    for (i = 0; i < numOfSeats; i++)
        pthread_create(&philosopher_tid[i], NULL, philosopher, (void *) i);

    for (i = 0; i < numOfSeats; i++)
        pthread_join(philosopher_tid[i], NULL);

    for (i = 0; i < numOfSeats; i++)
        pthread_cond_destroy(self + i);

    printf("Dinner is no more.\n");

    return 0;
}

void *philosopher(void *num)
{
    int id = (long) num;

    printf("Philsopher no. %d sits at the table.\n", id);

    // philosophers arrive at the table at various times
    usleep(SLEEP_TIME);

    int i;
    for (i = 0; i < numOfTurns; i++)
    {

            pickup(id);
            // pickup()
            // wait for a little
            printf("philo %d is eating!\n", id);
            usleep(2 * SLEEP_TIME); 
            // putdown 
            putdown(id);
        }

    printf(">>>>>> Philsopher no. %d finished meal. <<<<<<\n", id);

    pthread_exit(NULL);
}

