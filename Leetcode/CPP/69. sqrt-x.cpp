// Question Link: https://leetcode.com/problems/sqrtx/
// Author: Bihan Chakraborty
class Solution {
   public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int l = 1, h = x / 2, ans = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (mid == x / mid) {
                ans = mid;
                return ans;
            }
            if (mid > x / mid) {
                h = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};