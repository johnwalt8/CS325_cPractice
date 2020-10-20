/* insertionSort.c */
/* Walter Johnson, 2020-09-29 */

#include <stdio.h>
#include <stdlib.h>

int ternarySearch(int target, int A[], int firstIndex, int lastIndex);

int main(int argc, char* argv[])
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

    int target = 21;

    if (argc == 2)
    {
        target = atoi(argv[1]);
    }

    printf("argv[1] = %d\n", target);

    int targetIndex = ternarySearch(target, A, 0, 20);

    if (targetIndex == -1)
    {
        printf("target value not in array\n");
    }
    else
    {
        printf("A[%d] = %d\n", targetIndex, A[targetIndex]);
    }
}

int ternarySearch(int target, int A[], int firstIndex, int lastIndex)
{
    if (firstIndex == lastIndex)
    {
        if (A[firstIndex] == target)
        {
            return firstIndex;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int arrayLength = lastIndex - firstIndex + 1;
        int firstThird = firstIndex + 1*arrayLength/3;
        int secondThird = firstIndex + 2*arrayLength/3;
        if (A[firstThird] >= target)
        {
            return ternarySearch(target, A, firstIndex, firstThird);
        }
        else if (A[secondThird] >= target)
        {
            return ternarySearch(target, A, firstThird + 1, secondThird);
        }
        else
        {
            return ternarySearch(target, A, secondThird + 1, lastIndex);
        }
    }
}