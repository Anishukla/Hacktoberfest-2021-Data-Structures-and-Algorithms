//Done by Rahul Bansal

// problem statement
//Given an integer array nums, find three numbers whose product is maximum and 
//return the maximum product.

//solution

class Solution {
  //we created a class
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[nums.size()-1],nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
    }//Basically what we have done is if the negative number is bigger than the postive number in magnitude than we will take two
//numbers from left otherwise all the three numbers from the right.
    }
};
