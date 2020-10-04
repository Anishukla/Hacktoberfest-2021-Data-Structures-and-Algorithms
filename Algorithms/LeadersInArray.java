/*
An element is a leader if it is greater than all the elements to its right side.
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
author: poojagorai
*/

import java.util.*;

class LeaderInArray 
{ 
   public static void main(String[] args)  
    { 
        int arr[];
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        arr = new int[n];

        for (int i = 0; i < n; i ++) {
          arr[i] = sc.nextInt();
        }
        // Calculate leaders in the array
        for (int i = 0; i < n; i++)  
        {
          int j; 
          for (j = i + 1; j < n; j++)  
          { 
           // Check if elements is greater than ith element
            if (arr[i] < arr[j]) 
              break; 
            } 
          if (j == n)
            System.out.print("Leaders in array are " + arr[i] + " "); 
        } 
    }
} 
