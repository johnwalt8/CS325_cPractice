/* recursiveActivitySelector.c */
/* Walter Johnson, 2020-10-20 */

#include <stdio.h>
#include <stdlib.h>

int recursiveActivitySelector(int start[], int finish[], int index, int numActivities, int activities[]);
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

    printArray("intial activities", numActivities, activities);

    int numSelected = recursiveActivitySelector(start, finish, 0, numActivities, activities);

    printArray("activities", numSelected, activities);
}

int recursiveActivitySelector(int start[], int finish[], int index, int numActivities, int activities[])
{
    int numSelected = -7;
    int nextIndex = index + 1;
    while (nextIndex <= numActivities && start[nextIndex] < finish[index])
    {
        nextIndex = nextIndex + 1;
    }
    if (nextIndex < numActivities)
    {
        numSelected = recursiveActivitySelector(start, finish, nextIndex, numActivities, activities);
        activities[numSelected] = nextIndex;
        numSelected = numSelected + 1;
        printf("numSelected = %d\n", numSelected);
        printArray("intial activities", numActivities, activities);
        return numSelected;
    }
    else
    {
        return 0;
    }
    
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