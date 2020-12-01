/* fiboSteps.c */
/* Walter Johnson, 2020-11-29 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long int getWays(int A);

int main(int argc, char* argv[])
{
    int A = 13; // can't be larger than 91
    if (argc == 2)
    {
        A = atoi(argv[1]);
    }
    else
    {
        printf("Please include a postive integer as one command line argument.\n");
        return 0;
    }

    if (A > 91)
    {
        printf("I'm sorry, due to system limitations, the number of distinct ways to climb to the top cannot be calculated for staircases of more than 91 steps.\n");
        return 0;
    }
    else if (A < 0)
    {
        printf("I'm sorry, staircases can't have a negative number of steps.\n");
        return 0;
    }
    

    unsigned long long int distinctWaysToA = getWays(A);

    printf("Given a staircase of %d steps, taking one or two steps at a time, there are %lld distinct ways to climb to the top.\n", A, distinctWaysToA);
}

unsigned long long int getWays(int A)
{
    unsigned long long int previousTwo[] = {1, 1}; // base cases: steps 0 and 1

    int index = 1; // which previousTwo are we modifying
    int j = -7;
    for (j = 2; j <= A; j++)  // step 2 through step A
    {
        index = index == 0 ? 1 : 0;  // switch back and forth in previousTwo to store current
        previousTwo[index] = previousTwo[0] + previousTwo[1];
    }

    return previousTwo[index];
}