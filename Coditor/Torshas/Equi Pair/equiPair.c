#include<stdio.h>
#include<stdlib.h>
struct EquiPair
{
    int start;
    int end;
};
int calculateSliceSum(int *ar, int x, int y)
{
    int sum = 0;
    int z;
    for(z = x; z<= y; z++)
    {
        sum = sum + ar[z];
    }
    return sum;
}
int main(void)
{
    struct EquiPair *out;
    int *arr;
    int i;
    int t;
    int length;
    int j;
    int k;
    int firstSliceSum;
    int secondSliceSum;
    int thirdSliceSum;
    int flag;
     
    scanf("%d", &t);
    out = (struct EquiPair*)malloc(t*sizeof(struct EquiPair));
    for(k = 0; k<t; k++)
    {
        out[k].start = -1;
        out[k].end = -1;
    }
    for(i = 0; i<t;i++)
    {
        scanf("%d", &length);
        arr = (int *)malloc(length*sizeof(int));
        flag = 0;
        for(j = 0; j<length;j++)
        {
            scanf("%d", &arr[j]);
        }
        for(j = 1; j<length-3; j++)
        {
            for(k = j + 2; k<length - 1; k++)
            {
                firstSliceSum = calculateSliceSum(arr,0, j-1);
                secondSliceSum = calculateSliceSum(arr,j+1, k-1);
                thirdSliceSum = calculateSliceSum(arr,k+1, length - 1);
                if(firstSliceSum == secondSliceSum && secondSliceSum == thirdSliceSum)
                {   
                    out[i].start = j;
                    out[i].end = k; 
                    flag = 1;
                    break;
                }
                 
            }
            if(flag == 1)
                break;
        }
    }
    for(k = 0; k<t; k++)
    {
        printf("\nCase #%d: (%d,%d)", k+1, out[k].start, out[k].end);
    }
}