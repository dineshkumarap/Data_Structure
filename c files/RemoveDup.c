#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Removing duplicates in unsorted array...\n");
    int k=1,f;
    for(int i=1;i<n;i++)
    {
        f=1;
        for(int j=0;j<k;j++)
        {
            if(a[i]==a[j])
            {
                f=0;
                break;
            }
        }
        if(f)
            a[k++]=a[i];
    }
    for(int i=0;i<k;i++)
        printf("%d ",a[i]);
}