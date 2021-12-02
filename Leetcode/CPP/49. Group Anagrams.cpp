/*
    LOGIC:
    
    Two strings are anagrams if and only if their sorted strings are equal.
    So we just use a Hash Table data structure to group strings, where the key is the sorted string of its string.
    For example: strs = ["eat","tea","tan","ate","nat","bat"]
        ["ate","eat","tea"] forms a group, because they have the same key "aet"
        ["nat", "tan"] forms a group, because they have the same key "ant"
        ["bat"] forms a group, because they have the same key "abt"

*/

class Solution {
public:
    static bool comp(vector<string> vect1,vector<string> vect2){
        if(vect2.size()<vect1.size()){
            return true;
        }
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        
        for(auto itr:mp){
            sort(itr.second.begin(),itr.second.end());
            ans.push_back(itr.second);
        }
        sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};

/*
    Time Complexity: O(N * L)
    Space Complexity: O(N * L)

*/