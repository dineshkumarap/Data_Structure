#include<stdio.h>
#include<stdlib.h>

int binsearch(int a[],int f,int l,int s)
{
    if(f<=l)
    {
        int m=(l-f)/2+f;
        if(a[m]==s)
            return (1);
        if(a[m]>s)
            return(binsearch(a,f,m-1,s));
        else
            return(binsearch(a,m+1,l,s));
    }
    return(0);
}

int linsearch(int a[],int n,int s)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
            return(1);
    }
    return(0);
}

void merge(int a[],int f,int m,int l)
{
    int n1,n2;
    n1= (m-f) +1;
    n2= l-m;
    int s1[n1],s2[n2];
    int i,j,k;

    for(i=0;i<n1;i++)
        s1[i]=a[f+i];
    for(j=0;j<n2;j++)
        s2[j]=a[m+1+j];
    

    for(k=f,i=0,j=0; i<n1 && j<n2;k++)
    {
        if(s1[i]<s2[j])
        {
            a[k]=s1[i];
            i++;
        }
        else
        {
            a[k]=s2[j];
            j++;
        }
    }
    for(;i<n1;k++,i++)
        a[k]=s1[i];
    for(;j<n2;k++,j++)
        a[k]=s2[j];
}

void mersort(int a[],int f,int l)
{
    int m= ((l-f)/2) + f;
    if(f<l)
    {
        mersort(a,f,m);
        mersort(a,m+1,l);
        merge(a,f,m,l);
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Merge Sorting...");
    mersort(a,0,n-1);
    print(a,n);
    int s;
    printf("\nEnter the number to search in the list (Binary Search): ");
    scanf("%d",&s);
    if(binsearch(a,0,n-1,s))
        printf("Given number is in the list.");
    else    
        printf("Given number is not in the list.");
    printf("\nEnter the number to search in the list (Linear Search): ");
    scanf("%d",&s);
    if(linsearch(a,n,s))
        printf("Given number is in the list.");
    else    
        printf("Given number is not in the list.");
    return (0);
}
