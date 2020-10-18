class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        //Rotate elements by k turn step by step
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
