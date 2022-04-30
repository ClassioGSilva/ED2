#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMITEPROCESS 10

typedef struct process
{

} PROCESS;

typedef struct scheduler
{

} SCHEDULER;

int randomCycles()
{
    return rand() % 10;
}

int addProcess(int nCycles)
{
    return 0; // 0- Vazio; 1-Cheio
}

PROCESS *runProcess()
{
    return NULL;
}

SCHEDULER *statusScheduler()
{
    return NULL;
}

int randomStep()
{
    int r = rand() % 100 + 1;
    if (r <= 25)
        return 1;
    if (r <= 80)
        return 2;
    else
        return 3;
}

int main()
{
    PROCESS *p;
    SCHEDULER *e;
    int step = 1, countMachine = 0;
    while (countMachine <= 100)
    {
        if (step == 1)
        {
            addProcess(randomCycles());
        }
        else if (step == 2)
        {
            p = runProcess();
        }
        else
        {
            e = statusScheduler();
        }
        step = randomStep();
    }
}