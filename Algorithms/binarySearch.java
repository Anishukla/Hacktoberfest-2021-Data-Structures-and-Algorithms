import java.util.*;

public class binarySearch {
    static int BinarySearch(int arr[], int n, int item) {
        int start = 0;
        int end = n - 1;
        while (start <= end) {

            int mid = (start + (end - start) / 2);
            if (item == arr[mid]) {
                return mid;
            } else if (item < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i, index;
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("\nEnter the elements of the array: ");
        for (i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("\nEnter the item to be searched: ");
        int item = sc.nextInt();
        index = BinarySearch(arr, n, item);
        if (index == -1) {
            System.out.println("not found in the array!");
        } else {
            System.out.println("found at position " + index);
        }
    }
}
