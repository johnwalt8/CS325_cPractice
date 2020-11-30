/* fiboSteps.c */
/* Walter Johnson, 2020-11-29 */

#include <stdio.h>
#include <stdlib.h>

unsigned long int getWays(int A);

int main(int argc, char* argv[])
{
    int A = 7; // can't be larger than 47
    if (argc == 2)
    {
        A = atoi(argv[1]);
    }

    unsigned long int distinctWaysToA = getWays(A);

    printf("Given %d steps, there are %lld distinct ways to climb to the top.\n", A, distinctWaysToA);
}

unsigned long int getWays(int A)
{
    unsigned long int previousTwo[] = {1, 1}; // base cases: steps 0 and 1

    int index = 1;
    int j = -7;
    for (j = 2; j <= A; j++)
    {
        index = index == 0 ? 1 : 0;
        previousTwo[index] = previousTwo[0] + previousTwo[1];
    }

    return previousTwo[index];
}