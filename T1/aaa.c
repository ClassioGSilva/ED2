#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMITEPROCESS 10

typedef struct process
{
    int valuesP[LIMITEPROCESS];
    int firstp, lastp;

} PROCESS;

void initp(PROCESS *process)
{
    process->firstp = 0;
    process->lastp = process->firstp;
}

typedef struct scheduler
{
    int valuesS[LIMITEPROCESS];
    int firsts, lasts;

} SCHEDULER;

void inits(SCHEDULER *scheduler)
{
    scheduler->firsts = 0;
    scheduler->lasts = scheduler->firsts;
}

int isEmpty(PROCESS p)
{
    printf("\nEntrou nessa!");
    return (p.firstp == p.lastp && p.valuesP[p.firstp] == 0);
}

int randomCycles()
{
    return rand() % 10;
}

int addProcess(PROCESS *p, int nCycles)
{
    if (p->lastp == LIMITEPROCESS)
    {
        printf("Fila Cheia");
        return 0;
    }else{
        p->valuesP[p->lastp] = nCycles;
        printf("\n Id:%i | Ciclos:%i", p->lastp+1, p->valuesP[p->lastp]);
        p->lastp++;
        printf("\nEntrou");
        return 1;
    }
    
}

PROCESS *runProcess(PROCESS *p)
{
    printf("\nEntrou aqui");

    int value = 0;
    if (isEmpty(*p))
    {
        printf("\nErro fila esta vazia\n");
        return NULL;
    }

    if (p->firstp == LIMITEPROCESS){
        value = p->valuesP[p->firstp];
        printf("\nValor %i", value);
        value--;
        printf("\nValor %i", value);
        p->valuesP[p->lastp] = value;
        p->lastp++;
        p->firstp = 0;
    }
    else if (p->lastp == LIMITEPROCESS){
        value = p->valuesP[p->firstp];
        printf("\nValor %i", value);
        value--;
        printf("\nValor %i", value);
        p->valuesP[p->lastp] = value;
        p->firstp++;
        p->lastp = 0;
    }
    else
    {
        value = p->valuesP[p->firstp];
        printf("\nelseValor %i", value);
        value--;
        printf("\nelseValor %i", value);
        if(value == 0){
            printf("\nZerou");
            p->firstp++;
            return;
        }else{
            printf("\nFim da Fila");
            p->valuesP[p->lastp] = value;
            p->firstp++;
            return;
        }
    }
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
    PROCESS p;
    SCHEDULER e;
    int step = 1, countMachine = 0;

    initp(&p);
    inits(&p);


    while (countMachine <= 5)
    {
        printf("\nStep: %i", step);
        if (step == 1)
        {
            printf("\nAdd Num Ciclo");
            addProcess(&p, randomCycles());
        }
        else if (step == 2)
        {
            printf("\nExecutar Processo");
            p = *runProcess(&p);
        }
        else
        {
            printf("\nStatus do Processo");
            /*e = statusScheduler();*/
        }
        step = randomStep();
        countMachine++;
    }
}