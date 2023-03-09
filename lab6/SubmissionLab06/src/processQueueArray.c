/*
Lars Haavaldsen
COMP362
:)
*/
#include "processQueue.h"
#include <stdio.h>
#include <stdlib.h>

PROCESS *processTable;
int processTableSize = 0;
int processTableCapacity;


PROCESS **readyQueue;
int readyQueueSize = 0;
int readyQueueCapacity;

/***
 * constructor of the process table
 */
void createProcessTable(int capacity)
{
    processTable = (PROCESS *) malloc(capacity * sizeof(PROCESS));
    processTableCapacity = capacity;
}

/***
 * constructor of the ready queue
 */
void createReadyQueue(int capacity)
{
    readyQueue = (PROCESS **) malloc(capacity * sizeof(PROCESS *));
    readyQueueCapacity = capacity;
}

/***
 * adds a process and expands the table if necessary
 */
void addProcessToTable(PROCESS process)
{
    if (processTableSize >= processTableCapacity) //if array too small
    {
        processTableCapacity *= 2; //double capacity
        processTable = (PROCESS *) realloc(processTable, processTableCapacity * sizeof(PROCESS));
    }

    processTable[processTableSize] = process;
    processTableSize++;

}

/***
 * display the processes table
 */
void displayProcessTable()
{
    printf("PROCESSES:\n\nName    \tEntry\tBurst\n");
    for (int i = 0; i < processTableSize; i++)
    {
        printf("%-8s\t%3d   \t%3d   \n", processTable[i].name, processTable[i].entryTime, processTable[i].burstTime);
    }
    printf("\n");
}

/***
 * determines if any processes in the process table still need to execute
 */
//will determine if any processes in the process queue have more to execute
bool processesLeftToExecute()
{
    for(int i = 0; i < processTableSize; i++) {
        if(processTable[i].burstTime > 0) {
            return true;
        }
    }
    return false; //return 0 if all processes are complete
}

/***
 * adds any processes that arrive at the current time to ready queue
 */
void addArrivingProcessesToReadyQueue(int time)
{
    //for every process in process table
        // if the entry time is == time, add it to queue 
    for(int i = 0; i < processTableSize; i++) {
        if(processTable[i].entryTime == time) {
            addProcessToReadyQueue(&processTable[i]);
        }
    }
}

/***
 * adds a process to the ready queue and expands it if necessary
 */
void addProcessToReadyQueue(PROCESS *pointer)
{
    if (readyQueueSize >= readyQueueCapacity) //if array too small
    {
        readyQueueCapacity *= 2; //double capacity
        readyQueue = (PROCESS **) realloc(readyQueue, readyQueueCapacity * sizeof(PROCESS *));
    }
    // same as last time.. but on the ready queue
    readyQueue[readyQueueSize] = pointer;
    readyQueueSize++;

}

/***
 * removes a process from the ready queue and fills the "hole"
 */
void removeProcessFromReadyQueue(PROCESS *p)
{
    // use memmove
    // memmove(&queue[i], &queue[i+1], (size - (i+1) ) * sizeof(PROCESS *)) // try changing size to capacity
    
    for(int i = 0; i < readyQueueSize; i++) {
        if (readyQueue[i] == p) {
            memmove(&readyQueue[i], &readyQueue[i+1], (readyQueueSize - (i+1) ) * sizeof(PROCESS *));
        }
    }
    readyQueueSize--;
}

/***
 * fetches the first process from the ready queue
 */
PROCESS *fetchFirstProcessFromReadyQueue()
{
// probably should check if ready queue is empty
    // call remove
    PROCESS *first = readyQueue[0];
    
    removeProcessFromReadyQueue(first);
    return first;
}

/***
 * finds the shortest job in the ready queue
 */
PROCESS *findShortestProcessInReadyQueue()
{
    PROCESS *shorty = readyQueue[0];
    for (int i = 1; i < readyQueueSize; i++) {
        if(readyQueue[i]->burstTime < shorty->burstTime) {
            shorty = readyQueue[i];
        }
    }
    
    return shorty;
}

/***
 * displays the contents of the ready queue
 */
void displayQueue()
{
    int i;
    printf("QUEUE: ");

    if (readyQueueSize <= 0)
        printf("<empty>");
    else
    {
        for (i = 0; i < readyQueueSize; i++)
        {
            printf("%s(%d) ", readyQueue[i]->name, readyQueue[i]->burstTime);
        }
    }
}

/***
 * calculates and prints the average wait time using information in the process table
 */
void printAverageWaitTime()
{
    int i = 0;
    double sum = 0;
    for (i = 0; i < processTableSize; i++)
    {
        sum = sum + processTable[i].waitTime;
        printf("Process %s Wait Time: %.2lf\n", processTable[i].name, (double) processTable[i].waitTime);
    }
    printf("Average Wait Time: %.2lf\n", (sum / (double) processTableSize));
}

/***
 * clean up the process table
 */
void cleanUp()
{ 
    free(processTable);
    free(readyQueue);
}





