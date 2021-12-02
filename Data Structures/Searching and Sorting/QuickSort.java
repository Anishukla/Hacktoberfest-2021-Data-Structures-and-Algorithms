public class QuickSort {

    public void quicksort(int A[], int low, int high) {
        if(low<high) {
            int pi = partition(A,low,high);
            quicksort(A,low,pi-1);
            quicksort(A,pi+1,high);
        }
    }

    public int partition(int A[], int low, int high) {
        int pivot = A[low];
        int i = low+1;
        int j = high;
        do {
            while(i <= j && A[i] <= pivot)
                i = i + 1;
            while (i <= j && A[j] > pivot)
                j = j - 1;
            if (i <= j)
                swap(A,i,j);
        } while(i<j);
        swap(A,low,j);
        return j;
    }

    public void swap(int A[], int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    public void display(int A[], int n) {
        for(int i=0;i<n;i++)
            System.out.print(A[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        QuickSort s = new QuickSort();
        int A[] = {5, 3, 8, 9, 4, 6};
        System.out.print("Original Array: ");
        s.display(A, 6);
        s.quicksort(A, 0, A.length-1);
        System.out.print("Sorted Array: ");
        s.display(A, 6);
    }

}
