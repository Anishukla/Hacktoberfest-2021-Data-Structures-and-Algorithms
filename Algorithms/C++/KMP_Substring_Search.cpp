/* C++ implementation of KMP String matching algorithm. */
/* Author: Rohit-Varma */
/* The time complexity of the algorithm is O(n+m) and the space is also O(n+m), but can also be done in O(n) 
   for online queries, where n=size of pattern, m=size of text. */
#include <bits/stdc++.h>
using namespace std;

//we compute the prefix function pi[], it's defined below:
vector<int> kmp_string_match (string text,string pattern) {
	
	/*let s[0...n-1] be a string of length n, then pi[x] (0<=x<=n-1) is the 
	  length of longest proper prefix of substring s[0..x] which is also the suffix of this string */
    int m = (int)text.size();
    int n = (int)pattern.size();
    vector<int> indices;
    /* So if we append the pattern and text and calculate pi function, then the occurences of pi[x]=n denote 
	   the places where pattern p is a substring of text t.
       We use a foreign character "#" to prevent the counting of overlapping occurences in the text and pattern */
    string s = pattern + "#" + text;
    vector<int> pi(n+m+1,0);
    for (int i = 1; i < n+m+1 ; i++) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j]) 
		{
			j = pi[j-1];
		}
        if(s[i]==s[j]) j++;
        pi[i] = j;
        if(pi[i]==n)indices.push_back(i-2*n);
        /*We take index as i-2*n because we have appended pattern and text and 
		  i is the combined index in pattern+text at which the substring ends */
    }
    return indices;
}

int main()
{
	string text,pattern;
	//Our task is to search for occurences of "pattern" in the given "text".
	cin>>text;
	cin>>pattern;
	//We call the kmp_string_match function which can find if there is a substring p[0...n-1] in a text t[0...m-1]
	vector<int> indices = kmp_string_match(text,pattern);
	for(int i=0;i<indices.size();i++)
	{
		cout<<"Found occurence of pattern at index "<<indices[i]<<" of the text"<<endl;
	}
	if(indices.size()==0)cout<<"Pattern "<<pattern<<" doesn't occur in text "<<text<<endl;
}
