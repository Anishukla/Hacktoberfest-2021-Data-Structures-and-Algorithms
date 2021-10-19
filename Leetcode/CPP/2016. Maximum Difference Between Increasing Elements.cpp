class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1 , mn = INT_MAX;
        for(auto i : nums)
            if(mn >= i) mn = i;
            else ans = max(ans, i-mn);
        return ans;
    }
};
