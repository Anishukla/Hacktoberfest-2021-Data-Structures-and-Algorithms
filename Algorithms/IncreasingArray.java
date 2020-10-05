/*You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.On each turn,
you may increase the value of any element by one. What is the minimum number of turns required?

Example

Input:
5
3 2 5 1 7

Output:
5
*/

import java.util.*;
public class Increasing_array {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long count_step = 0;
        long z;

        int n = sc.nextInt();
        int a[] = new int[n];

        for (int x = 0; x < n; x++) {
            a[x] = sc.nextInt();
        }

        for (int y = 0; y < n - 1; y++) {
            // Compare the next and current values
            if (a[y + 1] < a[y]) {
                z = 0;
                z = a[y] - a[y + 1];
                a[y + 1] += z;
                count_step = count_step + z;
            }

        }
        System.out.println(count_step);
    }

}

// author : shobhnanayak99
