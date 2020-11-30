/* schedWithP.c */
/* Walter Johnson, 2020-09-29 */

#include <stdio.h>
#include <stdlib.h>

typedef struct jobs
{
    int numJobs;
    int j[64];
    int d[64];
    int p[64];
    int schedule[64];
    int penalties[64];
    int penalized[64];
    int penalty;
    int numPenalties;
} jobs;

void insertSortJobs(jobs *Jobs);
int printArray(char *aName, int length, int array[]);

int main(int argc, char* argv[])
{
    struct jobs Jobs = 
    {
        .numJobs = 20,
        .j = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        .d = {19, 18, 17, 1, 3, 5, 20, 20, 7, 11, 11, 11, 5, 9, 14, 6, 5, 4, 12, 2},
        .p = {1, 7, 5, 9, 3, 13, 14, 15, 0, 0, 0, 0, 19, 2, 3, 4, 11, 11, 10, 10},
        .schedule = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .penalties = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .penalized = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .penalty = 0,
        .numPenalties = 0
    };

    insertSortJobs(&Jobs);

    printArray("jobs", Jobs.numJobs, Jobs.j);
    printArray("deadlines", Jobs.numJobs, Jobs.d);
    printArray("penalties", Jobs.numJobs, Jobs.p);

    int i = -7;
    for (i = 0; i < Jobs.numJobs; i++)
    {   
        int j = Jobs.d[i] - 1; 
        while (Jobs.schedule[j] != 0 && j >= 0)
        {
            j = j - 1;
        }
        if (j >= 0)
        {
            Jobs.schedule[j] = Jobs.j[i];
        }
        else
        {
            j = Jobs.numJobs - 1;
            while (Jobs.schedule[j] != 0 && j > Jobs.d[i] - 1)
            {
                j = j - 1;
            }
            if (Jobs.schedule[j] == 0)
            {
                Jobs.schedule[j] = Jobs.j[i];
                Jobs.penalty = Jobs.penalty + Jobs.p[i];
                Jobs.penalties[Jobs.numPenalties] = Jobs.p[i];
                Jobs.penalized[Jobs.numPenalties] = Jobs.j[i];
                Jobs.numPenalties = Jobs.numPenalties + 1;
            }
            else
            {
                printf("something went just a little bit wrong");
            }
        }
    }
    
    printArray("Schedule", Jobs.numJobs, Jobs.schedule);
    printf("Number of Penalties = %d\n", Jobs.numPenalties);
    printf("Penalty = %d\n", Jobs.penalty);
    printArray("Penalties", Jobs.numPenalties, Jobs.penalties);
    printArray("Penalized", Jobs.numPenalties, Jobs.penalized);
}

void insertSortJobs(jobs *Jobs)
{
    int j = -7;
    int k = 0;
    for (j = 1; j < Jobs->numJobs; j++)
    {
        int jKey = Jobs->j[j];
        int pKey = Jobs->p[j];
        int dKey = Jobs->d[j];
        k = j - 1;
        while (k >= 0 && Jobs->p[k] < pKey)
        {
            Jobs->p[k + 1] = Jobs->p[k];
            Jobs->j[k + 1] = Jobs->j[k];
            Jobs->d[k + 1] = Jobs->d[k];
            k = k - 1;
        }
        Jobs->p[k + 1] = pKey;
        Jobs->j[k + 1] = jKey;
        Jobs->d[k + 1] = dKey;
    }
}


int printArray(char *aName, int length, int array[])
{
    printf("%s: {", aName);
    int k = -7;
    for (k = 0; k < length; k++)
    {
        printf("%d", array[k]);
        if (k < length - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}