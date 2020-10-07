class Solution {
    public boolean isPalindrome(int x) {
        int n = x;
        int sum=0;
        while(n>0){
            int a = n%10;
            sum = sum * 10 + a;
            n = n/10;
        }
        if(sum == x)
            return true;
        else
            return false;
    }
}