/* greedyActivitySelector.c */
/* Walter Johnson, 2020-10-20 */

#include <stdio.h>
#include <stdlib.h>

int greedyActivitySelector(int start[], int finish[], int activities[], int numActivities);
int printArray(char* aName, int length, int array[]);

int main(int argc, char* argv[])
{
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}; // start times
    int finish[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16}; // finish times

    int numActivities = sizeof(start)/sizeof(start[0]);

    int activities[numActivities];
    int i = -7;
    for (i = 0; i < numActivities; i++)
    {
        activities[i] = 0;
    }

    int numSelected = greedyActivitySelector(start, finish, activities, numActivities);

    printArray("activities", numSelected, activities);

    printf("Number of activities selected = %d\n", numSelected);
    printf("Activities:");
    for (i = 0; i < numSelected; i++)
    {
        printf(" %d", activities[i] + 1);
    }
    printf("\n");
    for (i = 0; i < numSelected; i++)
    {
        printf("%d\t%d\n", start[activities[i]], finish[activities[i]]);
    }
}

int greedyActivitySelector(int start[], int finish[], int activities[], int numActivities)
{
    activities[0] = 0; // the first activity has the earliest finish time, because sorted

    int index = 1, numSelected = 1;
    
    int nextIndex = -7;
    for (nextIndex = 2; nextIndex < numActivities; nextIndex++)
    {
        if (start[nextIndex] >= finish[index])
        {
            activities[numSelected] = nextIndex;
            numSelected = numSelected + 1;
            index = nextIndex;
        }
    }

    return numSelected;
}

int printArray(char* aName, int length, int array[])
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