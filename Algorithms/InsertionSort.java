import java.util.Arrays;

public class InsertionSort
{
   public static void insertionSort(int[]arr )
    {
        int j=1;
        int i;
        int k;
        while(j!=arr.length)
        {
            i=j-1;
           k=arr[j];
           if(k<=arr[i])
           {
               while (i >=0 &&arr[i]>k) {
                   arr[i + 1] = arr[i];
                   i--;
               }
               arr[i+1] = k;
           }
           j++;
        }

    }

    public static void main(String[] args) {
        int[] arr=new int[] {4,2,5,6,1,8,3,9};
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}
