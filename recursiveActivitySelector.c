/* recursiveActivitySelector.c */
/* Walter Johnson, 2020-10-20 */

#include <stdio.h>
#include <stdlib.h>

int* recursiveActivitySelector(start, finish, index, numActivities);
int printArray(char* aName, int length, int array[]);

int main(int argc, char* argv[])
{
    // int A = 21;
    // if (argc == 2)
    // {
    //     A = atoi(argv[1]);
    // }
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}; // start times
    int finish[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16}; // finish times

    int numActivities = sizeof(start)/sizeof(start[0]);

    int* activities = recursiveActivitySelector(start, finish, 0, numActivities);

    numActivities = sizeof(&activities)/sizeof(activities[0]);

    printArray("acitivities", numActivities, activities);
}

int* recursiveActivitySelector(start, finish, index, numActivities)
{
    int nextIndex = index + 1;
    while (nextIndex <= numActivities && start[nextIndex] < finish[index])
    {
        nextIndex = nextIndex + 1;
    }
    if (nextIndex <= index)
    {
        int* activities = recursiveActivitySelector(start, finish, nextIndex, numActivities);
        int sizeActivities = sizeof(&activities)/sizeof(activities[0]);
        static int newActivities[sizeActivities + 1];
        int i = -7;
        for (i = 0; i < sizeActivities; i++)
        {
            newActivities[i] = activities[i];
        }
        newActivities[sizeActivities] = nextIndex;
        return newActivities;
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