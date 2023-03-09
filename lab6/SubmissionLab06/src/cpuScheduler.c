/*
Lars Haavaldsen
COMP362
:)
*/

#include "cpuScheduler.h"
#include "processQueue.h"
#include <stdio.h>
#include<unistd.h>

static int quantum;

int main(int argc, char **argv)
{

#ifdef _DEBUG
    if (argc > 1)
    {
        freopen(argv[1], "r", stdin);
        printf("Reading input from file %ss.\n\n", argv[1]);
    }
    else
        printf("Reading input from stdin.\n\n");
#endif

    int time = 0; // simulated time

    ALGORITHM_PARAMS parameters = {
            .cpu = NULL, .algorithm = "",
            .step = NULL, .quantum = 0,
            .time = 0
    }; // simulation parameters

    // read the algorithm type and time quantum if necessary
    scanf("%s", parameters.algorithm);

    //check which algorithm was passed, set values accordingly
    if (strcmp(parameters.algorithm, "RR") == 0)
    {
        scanf("%d", &parameters.quantum);
        quantum = parameters.quantum;
        parameters.step = &rrStep;
    }
    else if (strcmp(parameters.algorithm, "FCFS") == 0)
        parameters.step = &fcfsStep;
    else if (strcmp(parameters.algorithm, "SJF") == 0)
        parameters.step = &sjfStep;
    else if (strcmp(parameters.algorithm, "SRTF") == 0)
        parameters.step = &srtfStep;
    else
    {
        printf("The job type input is not a valid input!");
        exit(EXIT_FAILURE);
    }

    scanf("\n"); // skip over the end of line marker

    printf("\nALGORITHM: %s", parameters.algorithm);
    if (strcmp(parameters.algorithm, "RR") == 0)
        printf("%3d", parameters.quantum);
    printf("\n\n");

    createProcessTable(INITIAL_CAPACITY); //create process table
    createReadyQueue(INITIAL_CAPACITY); //create ready queue

    readProcessTable(); //populate global process table
    displayProcessTable();

    printf("SIMULATION:\n\n");

    while (processesLeftToExecute())
    {
        addArrivingProcessesToReadyQueue(time);

        parameters.time = time;

        doStep(parameters.step, &parameters);

        displayTimeTick(time, parameters.cpu);

        if (parameters.cpu != NULL)
            parameters.cpu->burstTime--;

        time++;
    }

    printAverageWaitTime();

    cleanUp();

    return EXIT_SUCCESS;
}

/***
 * step executor
 */
void doStep(void (*func)(void *), void *param)
{
    func(param);
}

/***
 * function implementing a step of FCFS
 */
void fcfsStep(void *param)
{
    ALGORITHM_PARAMS *p = (ALGORITHM_PARAMS *) param;

    //if the cpu has nothing currently executing
    if (p->cpu == NULL || p->cpu->burstTime == 0)
    {
        p->cpu = fetchFirstProcessFromReadyQueue(); //start executing the first process in the ready queue
        if (p->cpu != NULL)
            p->cpu->waitTime = p->time - p->cpu->entryTime; // update the wait time
    }
}

/***
 * function implementing a step of SJF
 */
void sjfStep(void *param)
{
    ALGORITHM_PARAMS *p = (ALGORITHM_PARAMS *) param;
    if (p->cpu == NULL || p->cpu->burstTime == 0)
        {
            p->cpu = findShortestProcessInReadyQueue(); 
            removeProcessFromReadyQueue(p->cpu);
            if (p->cpu != NULL)
                p->cpu->waitTime = p->time - p->cpu->entryTime;
        }

}

/***
 * function implementing a step of SRTF
How to think about it:
    - Job shows up, for each step of the job, check to see if there is a shorter job in queue
    - If there is a shorter job, get rid of current job back to queue, and run shorter job
    - Repeat until none left
    

 */ 
void srtfStep(void *param)
{
    ALGORITHM_PARAMS *p = (ALGORITHM_PARAMS *) param;
    PROCESS* shorty;
    shorty = findShortestProcessInReadyQueue();

    // First do the basic stuff and check if we need to put in a new process
    if (p->cpu == NULL || p->cpu->burstTime == 0)
        {
            p->cpu = findShortestProcessInReadyQueue();
            removeProcessFromReadyQueue(p->cpu); 
            if (p->cpu != NULL)
                p->cpu->waitTime += p->time - p->cpu->offTime;
        } else {
            // check to see if there is a shorter job in queue
        if(shorty->burstTime < p->cpu->burstTime) {
            p->cpu->offTime = p->time;
            addProcessToReadyQueue(p->cpu); // get rid of current job back to queue
            removeProcessFromReadyQueue(shorty);
            p->cpu = shorty; // run shorter job 
            p->cpu->waitTime += p->time - p->cpu->offTime;
    }
        }
    

}

/***
 * function implementing a step of RR
 How to think about:
    - Pull job from queue, give it its time
    - Once job has gotten its time, swap to next process and repeat
    - Continue until all processes complete
 
 For times:
    - set the offtimes to time when the process is placed back into the queue
    - add that minus time rn to the wait time
 */
void rrStep(void *param)
{
    ALGORITHM_PARAMS *p = (ALGORITHM_PARAMS *) param;
    // first process from the queue or new process
    if (p->cpu == NULL || p->cpu->burstTime == 0)
            {
                p->cpu = fetchFirstProcessFromReadyQueue();
                quantum = p->quantum;
                if(p->cpu != NULL)
                    p->cpu->waitTime += p->time - p->cpu->offTime;
    } else {
        if(quantum == 0) {
            // set off times to rn
            p->cpu->offTime = p->time;

            addProcessToReadyQueue(p->cpu);
            p->cpu = fetchFirstProcessFromReadyQueue();

            p->cpu->waitTime += p->time - p->cpu->offTime;
            
            quantum = p->quantum;
        }
    }

    quantum--;
}

/***
 * fills the process table with processes from input
 */
int readProcessTable()
{
    PROCESS tempProcess = {
            .name = "",
            .entryTime = 0,
            .burstTime = 0,
            .offTime = 0,
            .waitTime = 0,
            .previous = NULL,
            .next = NULL
    };

    char *line = NULL;
    char *currPos;
    size_t len = 0;

    int counter = 0;
    int offset = 0;

    while (getline(&line, &len, stdin) != -1)
    {
        currPos = line;
        sscanf(currPos, "%s%n", tempProcess.name, &offset);
        currPos += offset;
        sscanf(currPos, "%d%n", &tempProcess.entryTime, &offset);
        tempProcess.offTime = tempProcess.entryTime; // simplifies computation of the wait time
        currPos += offset;
        sscanf(currPos, "%d", &tempProcess.burstTime);

        tempProcess.previous = NULL;
        tempProcess.next = NULL;

        addProcessToTable(tempProcess);

        counter++;
    }

    free(line);

    return counter;
}

void displayTimeTick(int time, PROCESS *cpu)
{
    printf("T%d:\nCPU: ", time);
    if (cpu == NULL)
        printf("<idle>\n");
    else
        printf("%s(%d)\n", cpu->name, cpu->burstTime);

    displayQueue();
    printf("\n\n");
}
