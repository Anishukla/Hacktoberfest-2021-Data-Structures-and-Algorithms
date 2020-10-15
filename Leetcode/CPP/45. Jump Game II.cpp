//Submitted by Ananya Singh (https://github.com/purpul)
// Question link: https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& arr) {
         int des = 0;
        int pos = 0;
        int jump = 0;
        for(int i=0;i<arr.size()-1;i++){
            
            des = max(des,i+arr[i]); 
            if(pos==i){
                pos = des;
                jump++;
            }
        }
        return jump;
        
    }
};

/*
    Complexity analysis
    Time complexity: O(n).
*/

