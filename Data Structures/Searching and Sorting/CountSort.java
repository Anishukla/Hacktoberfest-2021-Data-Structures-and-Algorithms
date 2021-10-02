public class CountSort {

    public int max(int A[], int n) {
        int temp = 0;
        for(int i=0;i<n;i++)
            if (A[i]>temp)
                temp = A[i];
        return temp;
    }
    public void countsort(int A[], int n) {
        int maxsize = max(A, n);
        int carray[] = new int[maxsize+1];
        for(int i=0;i<n;i++)
            carray[A[i]] = carray[A[i]] + 1;
        int i = 0;
        int j = 0;
        while(i < maxsize+1) {
            if(carray[i] > 0) {
                A[j] = i;
                j = j + 1;
                carray[i] = carray[i] - 1;
            }
            else
                i = i + 1;
        }
    }

    public void display(int A[], int n) {
        for(int i=0;i<n;i++)
            System.out.print(A[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        CountSort s = new CountSort();
        int A[] = {7, 3, 1, 9, 4, 2, 5, 3, 5};
        System.out.print("Original Array: ");
        s.display(A, 9);
        s.countsort(A, 9);
        System.out.print("Sorted Array: ");
        s.display(A, 9);
    }

}
