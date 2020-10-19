// 238.  Product of Array Except Self
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int N = nums.length;
        int[] output_arr = new int[N];
        output_arr[0] = 1;
        for (int i = 1; i< N ; i++){
            output_arr[i] = nums[i-1] * output_arr[i-1];
        }
        int R= 1;
        for (int i = N-1; i>=0; i--){
            output_arr[i]= output_arr[i] * R;
            R = R * nums[i];
        }
        return output_arr;
        }
}