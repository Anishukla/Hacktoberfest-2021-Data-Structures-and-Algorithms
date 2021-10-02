// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.3 MB, less than 80.02% of C++ online submissions for Valid Parentheses.
// Time Complexity --> O(n) ; where n is the size of string s
// Question link --> https://leetcode.com/problems/valid-parentheses/
// Code by Gopi vaibhav

class Solution {
public:
    bool isValid(string s) {
        stack<char> bgv;
        for(int i = 0; i < s.size(); i++) {
            if(bgv.empty()) {
                bgv.push(s[i]);
            } else {
                if(bgv.top() == '(' && s[i] == ')' || bgv.top() == '{' && s[i] == '}' || bgv.top() == '[' && s[i] == ']') {
                bgv.pop();
                } else {
                bgv.push(s[i]);
                }
            }
        }
        if(bgv.empty()) {
            return true;
        }
        return false;
    }
};