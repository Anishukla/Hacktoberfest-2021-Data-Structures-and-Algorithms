//Solution by: Harsh Jain
/* Problem: 58. Length of Last WordGiven a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
Example: Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
*/
int lengthOfLastWord(string s) 
    {
        int n=s.length();
        int count=0;
        for(int i=n;i>=0;i--)
        {
            if(s[i]>='A' && s[i]<='z')
            {
                count++;
            }
            
            if(s[i]==' ' && count>=1)
                break;
        }
        return count;
    }
