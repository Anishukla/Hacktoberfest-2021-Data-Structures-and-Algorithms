import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the factorial function below.
    static int factorial(int n) {
        if((n == 0) || (n == 1)) {
            return 1;
        } else {
            return n * factorial(n-1);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
        int n = in.nextInt();
        int abc = factorial(n);
        System.out.println(abc);
        }    
    }
}
