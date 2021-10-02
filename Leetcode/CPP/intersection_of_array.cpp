/*
Take two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as 
it shows in both arrays and you may return the result in any order.

Input: nums1 = [1,2,2,1] nums2 = [2,2]

Output: 2, 2

Complexities:
Time Complexity: O(nlogn+mlogm), where n and m are the lengths of the arrays. 
We sort two arrays independently, and then do a linear scan.

Space Complexity: from O(logn+logm) to O(n+m)
*/

class Solution {
public:
   
     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> nums;
          int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                nums.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if(nums1[i]<nums2[j]){
                ++i;
            }
            else{
                ++j;
            }
        }
        return nums;
        
    }
};
