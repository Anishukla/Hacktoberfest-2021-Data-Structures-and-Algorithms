/* 
  Leetcode problem: https://leetcode.com/problems/valid-parentheses/
  Author: Vashanth S
  
  LOGIC:  
  We maintain a stack to store the open brackets like '{', '[', '('
  When we get a closer brancker while traversing string, we check whether 
  the top character in stack is a matching open brancket, then its invalid.
  Also when we get a close character and if stack is empty, then its invalid.
  Finally we return if stack is empty implies as valid parantheses expression.
  
  Time complexity: O(N)
  Space complexity: O(N)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else 
            {
                if (st.empty())
                    return false;
                
                char openChar = st.top();
                
                if ((openChar == '{' && s[i] == '}') || (openChar == '(' && s[i] == ')') ||
                   (openChar == '[' && s[i] == ']'))
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};
