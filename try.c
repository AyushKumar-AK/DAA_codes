#include <stdio.h>
#include <stdlib.h>

void maxheapify(int arr[], int f, int size)
{
    int max = f;
    int l = 2 * f, r = 2 * f + 1, t;
    if (l <= size && arr[l] > arr[max])
    {
        max = l;
    }
    if (r <= size && arr[r] > arr[max])
    {
        max = r;
    }

    if (f != max)
    {
        t = arr[f];
        arr[f] = arr[max];
        arr[max] = t;
        maxheapify(arr, max, size);
    }
}

void maxheap(int arr[], int beg, int end)
{
    int i;
    for (i = end / 2; i >= beg; i--)
        maxheapify(arr, i, end);
}

void heapsort(int arr[], int size)
{
    int i, t;
    maxheap(arr, 0, size - 1);
    for (i = size - 1; i >= 1; i--)
    {
        t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        maxheapify(arr, 0, i - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:  ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    heapsort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
