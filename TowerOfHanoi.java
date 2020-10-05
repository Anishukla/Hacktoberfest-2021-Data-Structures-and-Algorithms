1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.
"""

package com.DataStructures_Algorithms;
import java.util.Scanner;

public class TowerOfHannoi {
    public static void main(String[] args) {
        Scanner read=new Scanner(System.in);
        System.out.println("welcome to the tower of hanoi solve");
        System.out.println("enter the number of the blocks in the tower");
        int n=read.nextInt();
        System.out.println("your solution is ready  ...........");
        TowerOfHannoi.solve(3,'s','d','a');

    }
    static void solve(int n,char source ,char destination,char auxillary)
    {
        if(n>0)
        {
            solve(n-1,source,auxillary,destination);
            System.out.println("move the disk from "+source+" to  "+destination);
            solve(n-1,auxillary,destination,source);
        }

    }

}
