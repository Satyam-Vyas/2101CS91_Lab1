// C program to sort an array using different sorting methods
#include <stdio.h>
#include <math.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min_idx;

    // moving boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Finding minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }

        // Swapping found and first element
        if (min_idx != i)
        {
            swap(&a[min_idx], &a[i]);
        }
    }
}

int main()
{
    int n, m, a[1000];
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("methods to sort your array\n");
    printf("1- Insertion Sort,2- Selection Sort,3- Bubble Sort,4- Merge Sort,5- Quick Sort \n");
    printf("Enter preferred Sorting Method: ");
    switch (m)
    {
    case 1:
        insertionSort(a, n);
        print(a, n);
        break;
    case 2:
        selectionSort(a, n);
        print(a, n);
        break;
    case 3:
        bubbleSort(a, n);
        print(a, n);
        break;
    case 4:
        mergeSort(a, 0, n - 1);
        print(a, n);
        break;
    case 5:
        quicksort(a, 0, n - 1);
        print(a, n);
        break;
    default:
        printf("Please enter valid option of sorting method");
        break;
    }
    scanf("%d", &m);
    return 0;
}