import java.util.*;
class BubbleSort
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a[];
        int i=0,j=0,l=0,d=0;
        System.out.println("Enter number of terms to sort");
        l=sc.nextInt();
        a=new int[l];
        System.out.println("Enter "+l+" numbers");
        for(i=0;i<l;i++)
        {
            a[i]=sc.nextInt();
        }
        for(i=0;i<l-1;i++)
        {
            for(j=0;j<l-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    d=a[j];
                    a[j]=a[j+1];
                    a[j+1]=d;
                }
            }
        }
        System.out.println("After Sorting");
        for(i=0;i<l;i++)
        {
            System.out.println(a[i]);
        }
    }
}
        