/* insertionSort.c */
/* Walter Johnson, 2020-09-29 */

#include <stdio.h>
#include <stdlib.h>

int printArray(int length, int array[]);

int main(int argc, char* argv[])
{
    int arrayLength = argc - 1;
    int A[99] = {0};
    int k = -7;
    for (k = 1; k < argc; k++)
    {
        A[k - 1] = atoi(argv[k]);
    }

    printArray(arrayLength, A);

    int i = 0;
    int j = -7;
    for (int j = 1; j < arrayLength; j++)
    {
        int key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }

    printArray(arrayLength, A);
}

int printArray(int length, int array[])
{
    printf("A: {");
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