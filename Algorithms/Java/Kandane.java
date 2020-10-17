import java.io.*; 
import java.util.*; 
// Java program to print largest contiguous array sum 
class Kandane 
{ 
	public static int maxSubArraySum(int a[],int n) 
	{ 
		int size = a.length; 
		int max_so_far = Integer.MIN_VALUE, max_ending_here = 0; 

		for (int i = 0; i < size; i++) 
		{ 
			max_ending_here = max_ending_here + a[i]; 
			if (max_so_far < max_ending_here) 
				max_so_far = max_ending_here; 
			if (max_ending_here < 0) 
				max_ending_here = 0; 
		} 
		return max_so_far; 
	} 
	public static void main (String[] args) 
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
		System.out.println("Maximum contiguous sum is " + 
									maxSubArraySum(ar,n)); 
	} 
} 
