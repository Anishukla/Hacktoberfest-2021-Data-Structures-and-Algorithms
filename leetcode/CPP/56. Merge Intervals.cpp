// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        if(intervals.size() ==0) return output;
        sort(intervals.begin(), intervals.end());
        auto temp = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(temp[1]>=intervals[i][0]){
                temp[1] = max(temp[1], intervals[i][1]);
            }else{
                output.push_back(temp);
                temp=intervals[i];
            }
        }
        output.push_back(temp);
        return output;
    }
};