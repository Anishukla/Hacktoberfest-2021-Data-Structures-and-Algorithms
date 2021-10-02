/*
    LOGIC:    
    Sort nums in increasing order.
    We fix nums[i], nums[j] by iterating the combination of nums[i], nums[j], then the problem now become to very classic problem 1. Two Sum.
    By using two pointers, one points to left, the other points to right, remain = target - nums[i] - nums[j].
        If nums[left] + nums[right] == remain
            Found a valid quadruplets
        Else if nums[left] + nums[right] > remain
            Sum is bigger than remain, need to decrease sum by right -= 1
        Else:
            Increasing sum by left += 1.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            for(int j=i+1;j<nums.size()-2;j++){
                    
                    if(j>i+1 && nums[j]==nums[j-1]){
                        continue;
                    }
                    int start=j+1;
                    int end=nums.size()-1; 
                    while(start<end){
                        
                        int sum=nums[i]+nums[j]+nums[start]+nums[end];
                        if(sum==target){
                            
                            ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                            
                            while(start<end && nums[start]==nums[start+1]){
                                start++;
                            }
                            while(start<end && nums[end]==nums[end-1]){
                                end--;
                            }
                            start++;
                            end--;
                        }
                        else if(sum<target){
                            start++;
                        }
                        else{
                            
                            end--;
                        }
                    }    
                }
           
        }
        return ans;
    }
};
/*
    Time Complexity: O(n^3)
    Space Complexity: O(sorting algo)
*/