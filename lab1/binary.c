//binary search implementation in c

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i,n,search,first,last,middle;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&search);
    first=0;
    last=n-1;
    middle=(first+last)/2;
    while(first<=last)
    {
        if(a[middle]<search)
        {
            first=middle+1;
        }
        else if(a[middle]==search)
        {
            printf("%d found at location %d\n",search,middle+1);
            break;
        }
        else
        {
            last=middle-1;
        }
        middle=(first+last)/2;
    }
    if(first>last)
    {
        printf("Not found\n");
    }
    return 0;
}

// output
// Enter the number of elements
// 5
// Enter the elements
// 1
// 2
// 3
// 4
// 5
// Enter the element to be searched
// 3
// 3 found at location 3
