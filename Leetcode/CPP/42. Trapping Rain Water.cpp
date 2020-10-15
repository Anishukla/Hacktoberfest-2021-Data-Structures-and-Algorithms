//Submitted by Ananya Singh (https://github.com/purpul)
// Question link: https://leetcode.com/problems/trapping-rain-water/

/*
  Algorithm

  Find maximum height of bar from the left end upto an index i in the array left.
  Find maximum height of bar from the right end upto an index i in the array right.
  Iterate over the height array and update ans:
  Add min(left[i],right[i])−height[i] to ans

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0; 
        int n=height.size();
        if(n==0)
            return 0;
        int left[n];
        int right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i - 1]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        for (int i = 0; i < n; i++) 
        water += min(left[i], right[i]) -height[i]; 
  
    return water;
    }
};



/*
    Complexity analysis

    Time complexity: O(n).
        We store the maximum heights upto a point using 2 iterations of O(n)each.
        We finally update ans using the stored values in O(n).
    Space complexity: O(n).

*/
