/* roadTrip.c */
/* Walter Johnson, 2020-09-29 */

#include <stdio.h>
#include <stdlib.h>

int printArray(char *aName, int length, int array[]);

int main(int argc, char* argv[])
{
    int X[] = {3, 7, 11, 14, 21, 28, 29, 33, 39, 44, 47, 49, 50, 51, 53, 57, 60, 64, 67, 71, 75};
    int n = sizeof(X)/sizeof(X[0]);
    int d = 7;

    if (argc > 1)
    {
        d = atoi(argv[1]);
    }

    printArray("X", n, X);

    int h[n];
    h[0] = 0;
    int i = 0;
    int j = -7;
    for (j = 1; j < n; j++)
    {
        if ((X[j] - h[i]) > d)
        {
            i = i + 1;
            h[i] = X[j - 1];
        }
    }
    i = i + 1;
    h[i] = X[n - 1];

    printf("number of days = %d\n", i);
    printArray("Hotels", i + 1, h);
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