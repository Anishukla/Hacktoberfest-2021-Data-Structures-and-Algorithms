 // 852.Peak Index in a Mountain Array
 class peak_index {

    public static void main(String[] args) {

        int[] arr = {-4, -3, -2, 0, -2, -3, -4, -5};
        System.out.print("The greatest element is found at posn.: " + peakIndexInMountainArray(arr));
    }

    public static int peakIndexInMountainArray(int[] arr) {
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
}