//done by sujaykummari

// problem statement
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order

//solution
/*
Runtime: 564 ms, faster than 10.10% of C++ online submissions for Two Sum.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Two Sum.
*/
class Solution {
  //we created a class
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //we have initilised the vector for space complexity
        int a=0;
        int b=0;
        for(int i=0;i<nums.size()-1;i++)
          //.size to get the size of vector
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                  //we checked if the sum is equal to target 
                {
                    a=i;
                    b=j;
                }
            }
        }
        return {a,b};
      //we returned the output
    }
};
