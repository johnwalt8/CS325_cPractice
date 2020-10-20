/* makingChange.c */
/* Walter Johnson, 2020-10-18 */

#include <stdio.h>
#include <stdlib.h>

int printArray(char* aName, int length, int array[]);

int main(int argc, char* argv[])
{
    int A = 21;
    if (argc == 2)
    {
        A = atoi(argv[1]);
    }
    int V[] = {1, 5, 7, 10, 25, 50, 77, 100};

    int numCoins[A + 1];
    int numDenomimations = sizeof(V)/sizeof(V[0]);
    int coinList[A + 1]; // [numDenomimations];
    int j = -7;
    for (j = 0; j <= A; j++)
    {
        numCoins[j] = __INT_MAX__;
        // int i = -7;
        // for (i = 0, i < numDenomimations, i++)
        // {
            coinList[j] = 0; // [i] = 0;
        // }
    }
    numCoins[0] = 0;

    int min = __INT_MAX__;
    int p = -7;
    for (p = 1; p <= A; p++)
    {
        int min = __INT_MAX__;
        int coin = -7;
        int i = -7;
        for (i = 0; i < numDenomimations; i++)
        {
            if (V[i] <= p)
            {
                if ((1 + numCoins[p - V[i]]) < min)
                {
                    min = (1 + numCoins[p - V[i]]);
                    coin = i;
                }
            }
        }
        numCoins[p] = min;
        coinList[p] = coin;
    }

    printArray("numCoins", A + 1, numCoins);
    printArray("coinList", A + 1, coinList);

    printf("coins: ");
    j = A; 
    while (j > 0)
    {
        printf(" %d", V[coinList[j]]);
        j = j - V[coinList[j]];
    }
    printf("\n");
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