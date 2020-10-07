/* stoogeSort.c */
/* Walter Johnson, 2020-10-06 */

#include <stdio.h>
#include <stdlib.h>

int printArray(char aName, int length, int array[]);
int stoogeSort(int A[], int firstIndex, int arrayLength);
int ceilingTwoThirdsN(int n);

int main(int argc, char* argv[])
{
    int arraySize = argc - 1;
    int A[99] = {0};
    if (arraySize == 0)
    {
        int val = 11;
        int i = -7;
        for (i = 0; i < 7; i++)
        {
            A[i] = val;
            val = val - 2;
        }
        arraySize = 6;
    }
    else
    {
        int k = -7;
        for (k = 1; k < argc; k++)
        {
            A[k - 1] = atoi(argv[k]);
        }
    }

    printArray('A', arraySize, A);

    stoogeSort(A, 0, arraySize - 1);

    printArray('A', arraySize, A);
}

int stoogeSort(int A[], int firstIndex, int lastIndex)
{
    int arrayLength = lastIndex - firstIndex + 1;
    if (arrayLength == 2 && A[firstIndex] > A[lastIndex])
    { // swap A["0"] and A["1"]
        int temp = A[firstIndex];
        A[firstIndex] = A[lastIndex];
        A[lastIndex] = temp;
    }
    else if (arrayLength > 2)
    {
        int m = ceilingTwoThirdsN(arrayLength);
        stoogeSort(A, firstIndex, firstIndex + m - 1);
        stoogeSort(A, lastIndex - m + 1, lastIndex);
        stoogeSort(A, firstIndex, firstIndex + m - 1);
    }
}

int printArray(char aName, int length, int array[])
{
    printf("%c: {", aName);
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

int ceilingTwoThirdsN(int n)
{
    return (1 + (((2 * n) - 1) / 3));
}