import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

 private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int length = scanner.nextInt();
        scanner.nextLine();
        while (length > 0) {
            String str = scanner.nextLine();

            char arr[] = str.toCharArray();
            int len = str.length();

            for (int x = 0; x < len; x = x + 2) {
                System.out.print(arr[x]);
            }
            System.out.print(" ");
            for (int x = 1; x < len; x = x + 2) {
                System.out.print(arr[x]);
            }
            System.out.println();
            length--;
        }
    }
}

