class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> a, b, c;
        for(auto i : nums1) a.insert(i);
        for(auto i : nums2) b.insert(i);
        for(auto i : nums3) c.insert(i);
        set<int> res;
        for(auto i : a) if(b.find(i)!=b.end() || c.find(i)!=c.end()) res.insert(i);
        for(auto i : b) if(c.find(i)!=c.end() || a.find(i)!=a.end()) res.insert(i);
        for(auto i : c) if(a.find(i)!=a.end() || b.find(i)!=b.end()) res.insert(i);
        vector<int> ret;
        for(auto i : res) ret.push_back(i);
        return ret;
    }
};
