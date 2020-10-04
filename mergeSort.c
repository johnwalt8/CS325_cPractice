/* mergeSort.c */
/* Walter Johnson, 2020-09-29 */

#include <stdio.h>
#include <stdlib.h>

int printArray(char aName, int length, int array[]);
int merge(int A[], int start, int length, int lengthA);
int mergeSort(int A[], int start, int length);

int main(int argc, char* argv[])
{
    int arrayLength = argc - 1;
    int A[99] = {0};
    if (arrayLength == 0)
    {
        int val = 11;
        for (int i = 0; i < 7; i++)
        {
            A[i] = val;
            val = val - 2;
        }
        arrayLength = 6;
    }
    else
    {
        for (int k = 1; k < argc; k++)
        {
            A[k - 1] = atoi(argv[k]);
        }
    }

    printArray('A', arrayLength, A);

    mergeSort(A, 1, arrayLength);

    printArray('A', arrayLength, A);
}

int mergeSort(int A[], int start, int length)
{
    if (start < length)
    {
        int lengthL = (start + length)/2;
        mergeSort(A, start, lengthL);
        mergeSort(A, lengthL + 1, length);
        merge(A, start, lengthL, length);
    }
}

int merge(int A[], int start, int length, int lengthA)
{
    int lengthL = length - start + 1;
    int lengthR = lengthA - length;
    int leftArray[lengthL];
    int rightArray[lengthR];

    for (int i = 1; i <= lengthL; i++)
    {
        leftArray[i - 1] = A[start + i - 2];
    }

    for (int j = 1; j <= lengthR; j++)
    {
        rightArray[j - 1] = A[length + j - 1];
    }

    int i = 1, j = 1;
    for (int k = start; k <= lengthA; k++)
    {
        if (i <= lengthL && j <= lengthR)
        {
            if (leftArray[i - 1] <= rightArray[j - 1])
            {
                A[k -1] = leftArray[i - 1];
                i = i + 1;
            }
            else
            {
                A[k - 1] = rightArray[j - 1];
                j = j + 1;
            }
        }
        else if (i <= lengthL)
        {
            A[k- 1] = leftArray[i - 1];
            i = i + 1;
        }
        else if (j <= lengthR)
        {
            A[k - 1] = rightArray[j - 1];
            j = j + 1;
        }
    }
}

int printArray(char aName, int length, int array[])
{
    printf("%c: {", aName);
    for (int k = 0; k < length; k++)
    {
        printf("%d", array[k]);
        if (k < length - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}