//merge sort
#include<stdio.h>
void merge(int a[],int ,int ,int);
void merge_sort(int a[],int ,int);
int main()
{
    int a[10],i,n,j,k;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("A[%d]= ",i);
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("The sorted array is:");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void merge_sort(int a[], int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(a,beg,mid);
        merge_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void merge(int a[],int beg, int mid, int end)
{
    int i=beg, j=mid+1, index=beg, temp[10], k;
    while((i<=mid)&&(j<=end))
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    {
        a[k]=temp[k];
    }
}

