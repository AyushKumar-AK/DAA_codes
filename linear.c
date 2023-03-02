//linear search

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements:  ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at index %d", i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element not found");
    }
    return 0;
}