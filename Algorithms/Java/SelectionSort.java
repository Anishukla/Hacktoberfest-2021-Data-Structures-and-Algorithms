class selection_sort {
    public static void main(String[] args) {
        int[] arr = {15, 14, 13, 12, 11, 10, 9, 8};
        selectionSort(arr);
        display(arr);
        
    }

    public static void selectionSort(int[] arr) {
        for (int counter = 0; counter < arr.length; counter++) {
            int min = counter;

            for(int j=counter+1; j<=arr.length-1; j++){
                if(arr[j] < arr[min])
                    min=j;
            }

            int temp = arr[min];
            arr[min] = arr[counter];
            arr[counter] = temp;
        }  
    }

    public static void display(int[] arr) {
        int[] var1 = arr;
        int var2 = arr.length;

        for(int var3 = 0; var3 < var2; ++var3) {
            int j = var1[var3];
            System.out.println(j);
        }
    }    
}

//time complexity of selection sort is O(n^2)
