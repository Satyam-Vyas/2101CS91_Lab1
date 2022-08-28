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

void bubbleSort(int arr[], int n) 
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]); //swapping
        }
    }
}
void merge(int arr[], int p, int q, int r) {
  int n = q - p + 1;
  int m = r - q;

  int L[n], M[m];

  for (int i = 0; i < n; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < m; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n && j < m) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < m) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // the array is divided into two subarrays about m
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r); //merging sorted subarrays
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