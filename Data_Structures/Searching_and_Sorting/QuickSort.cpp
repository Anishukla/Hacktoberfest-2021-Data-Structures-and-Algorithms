#include<stdio.h>
int partition(int a[],int beg,int end);
void quick_sort(int a[],int beg,int end);
int main()
{
    int arr[10],i,n,j,k;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    printf("The sorted array is:");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
int partition(int a[],int beg,int end)
{
    int left,right,temp,loc,flag=0;
    loc=left=beg;
    right=end;
    while(flag!=1)
    {
        while((a[loc]<=a[right])&&(loc!=right))
            right--;
        if(loc==right)
            flag=1;
        else if(a[loc]>a[right])
        {
            temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        if(flag!=1)
        {
            while((a[loc]>=a[left])&&(loc!=left))
                left++;
            if(loc==left)
                flag=1;
            else if(a[loc]<a[left])
            {
                temp=a[loc];
                a[loc]=a[left];
                a[left]=temp;
                loc=left;
            }
        }
    }
    return loc;
}
void quick_sort(int a[],int beg,int end)
{
    int loc;
    if(beg<end)
    {
        loc=partition(a,beg,end);
        quick_sort(a,beg,loc-1);
        quick_sort(a,loc+1,end);
    }
}

