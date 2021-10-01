// When to use this sorting technique?
// Whenever you are given an array or list of numbers in range of [1, n].
// It can also be from [0, n-1]. Basically it has to be continous.
// eg. [3, 2, 1, 4, 5]; [1, n] where n is 5.
// It's a good algorith as it worst case scenario is O(n). 

import java.util.Arrays;

public class Main
{
 public static void main(String[] args) 
    {
        int[] arr = {3, 5, 2, 1, 4};
        cyclicsort(arr);
        System.out.println(Arrays.toString(arr));
    }
    
    static void cyclicsort(int[] arr)
    {
        int i = 0;
        while(i < arr.length)
        {
            int correct = arr[i] - 1; // keep in mind that array starts with 0, thus we have to // subtract 1
            if(arr[i] != arr[correct])
            {
                swap(arr, i, correct);
            }
            else
            {
                i++;
            }
        }
    }
    
    static void swap(int[] arr, int first, int second)
    {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}


