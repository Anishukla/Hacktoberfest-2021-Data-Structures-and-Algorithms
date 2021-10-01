//1095. Find in Mountain Array
import java.util.Scanner;

class search_mountain {
    public static void main(String[] args) {
        int[] arr = {-4, -3, -2, 0, -2, -3, -4, -5};

        System.out.print("Kindly enter the item to be searched: ");
        Scanner scn = new Scanner(System.in);
        int item = scn.nextInt();

        System.out.print("The given element is found at posn.: " + peakIndexInMountainArray(arr, item));
        scn.close();
        
    }

    public static int peakIndexInMountainArray(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid+1]) {

                end = mid;
            } else {
                start = mid + 1; 
            }
        }
        return start; 
    } 

    public static int binarySearch(int[] arr, int item,int a_elem, int d_elem){

        int start = arr[0];
        int end = arr.length -1;

        if(start < end){

            int low = 0;
            int high = a_elem;
            
            while(low <= high){
                int mid = (low + high)/2;

                if (arr[mid] < item){
                    low = mid +1;
                }
                else if (arr[mid] > item){
                    high = mid - 1;
                }
                else{
                    return mid;
                }
            }
        }
        
        else{
            int low = a_elem +1;
            int high = arr.length - 1;

            while(high <= low){
                int mid = (low + high)/2;

                if (arr[mid] < item){
                    low = mid -1;
                }
                else if (arr[mid] > item){
                    high = mid + 1;
                }
                else{
                    return mid;
                }
            }
        }
        return -1;
    }
}
