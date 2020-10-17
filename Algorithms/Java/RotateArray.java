// Java program to rotate an array by 
// d elements 
import java.util.*;
class RotateArray { 
	public static void leftRotate(int arr[], int d, int n) 
	{ 
		for (int i = 0; i < d; i++) 
			leftRotatebyOne(arr, n); 
	} 

	public static void leftRotatebyOne(int arr[], int n) 
	{ 
		int i, temp; 
		temp = arr[0]; 
		for (i = 0; i < n - 1; i++) 
			arr[i] = arr[i + 1]; 
		arr[i] = temp; 
	} 

	public static void printArray(int arr[], int n) 
	{ 
		for (int i = 0; i < n; i++) 
			System.out.print(arr[i] + " "); 
	} 
	public static void main(String[] args) 
	{   Scanner sc=new Scanner(System.in);
		System.out.println("Enter no. of array element :");
        int n=sc.nextInt();
		int ar[]=new int[n];
        System.out.println("Enter array elements: ");
        for(int i=0;i<n;i++)
        {
              ar[i]=sc.nextInt();
        } 
        System.out.println("Enter no. by which array must rotate :");
        int d=sc.nextInt();
		leftRotate(ar, d, n); 
		printArray(ar, n); 
	} 
} 

