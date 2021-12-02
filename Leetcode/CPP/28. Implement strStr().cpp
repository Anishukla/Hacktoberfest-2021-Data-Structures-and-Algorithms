//TIME COMPLEXITY: O(n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1=haystack.size();//haystack
        int size2=needle.size();//needle
        if(size2==0){
            return size2;
        }
        //Code to find the longest prefix suffix
        vector<int> lps(size2);
        int start=0;
        int end=1;
        while(end<size2){
            if(needle[start]==needle[end]){
                lps[end]=start+1;
                start++;
                end++;
            }
            else if(start==0){
                end++;
            }
            else{
                start=lps[start-1] ;
            }
            
        }
        //Code for implementing KMP algo
        int idx1=0;//haystack
        int idx2=0;//needle
        while(idx1<size1 && idx2<size2){
            if(haystack[idx1]==needle[idx2]){
                idx1++;
                idx2++;
            }
            else if(idx2==0){
                idx1++;
            }
            else{
                idx2=lps[idx2-1];
            }
        }
        if(idx2==size2){
            return idx1-idx2;
        }
        return -1;
    }
};