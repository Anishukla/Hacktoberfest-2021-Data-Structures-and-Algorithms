// Java program for implementation of QuickSort 
import java.util.*;
class QuickSort 
{ 
	public static int partition(int arr[], int low, int high) 
	{ 
		int pivot = arr[high]; 
		int i = (low-1);  
		for (int j=low; j<high; j++) 
		{ 
			
			if (arr[j] < pivot) 
			{ 
				i++; 
				int temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp; 
			} 
		} 
		int temp = arr[i+1]; 
		arr[i+1] = arr[high]; 
		arr[high] = temp; 

		return i+1; 
	} 

	public static void sort(int arr[], int low, int high) 
	{ 
		if (low < high) 
		{ 
			
			int pi = partition(arr, low, high); 
			sort(arr, low, pi-1); 
			sort(arr, pi+1, high); 
		} 
	} 
	public static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i]+" "); 
		System.out.println(); 
	} 
	public static void main(String args[]) 
	{ 
		
                Scanner sc=new Scanner(System.in);
                System.out.println("Enter no. of array element :");
                int n=sc.nextInt();
		int ar[]=new int[n];
                System.out.println("Enter array elements: ");
                for(int i=0;i<n;i++)
                {
                    ar[i]=sc.nextInt();
                 }
                System.out.println("Array before sorting");
                printArray(ar); 
		sort(ar, 0, n-1); 
		System.out.println("sorted array"); 
		printArray(ar); 
	} 
} 

