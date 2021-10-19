class Solution {
public:
    bool areNumbersAscending(string s) {
        bool res = true;
        vector<int> numbers;
        int curr = -1;
        s += " ";
        for(auto i : s)
        {
            if(i<='9' && i>='0')
            {
                if(curr==-1) curr = 0;
                curr = curr*10 + (i-'0');
            }
            else if(curr!=-1)
                numbers.push_back(curr) , curr = -1;
        }
        
        for(int i = 1 ; i < numbers.size() ; i++) if(numbers[i]<=numbers[i-1]) res = false;
        
        return res;
    }
};
