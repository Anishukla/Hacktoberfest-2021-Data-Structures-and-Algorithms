/* By Shashank Gupta (Github , Codeforces , Codechef and Atcoder Handle - Shashank2409) */

/*Rabin Karp is a pattern searching algorithm. Unlike Naive pattern searching method, it uses a Hash function to reduce the number
of times a pattern is compared with the text. Though the average case complexity of this algorithm is O(n + m), bue due to Spurious hits,
the worst case complexity of this algorithm is O(n*m). */

#include<bits/stdc++.h>
using namespace std;
/* The value of total_char can be changed if lesser no of characters are used */
const int total_char = 26 , MOD = 1e9+7;

bool checkEqual(string text , string pat , int start){
	for(int i = start; i < pat.size(); i++)
		if(text[i] != pat[i - start]) return 0;
	return 1;
}

int main(){
	string text , pat;
	long long text_hash = 0 , pat_hash = 0;
	vector<int>ans;
	cin>>text>>pat;
	if(text.size() < pat.size()){
		cout<<"0\n";
		return 0;
	}
	long long max_power = 1;
	for(int i = 1; i < pat.size(); i++)
		max_power = (max_power * total_char)%MOD;
	
	/* To find the hash values of 1st pat.size() characters */
	for(int i = 0; i<pat.size(); i++){
		text_hash = ((text_hash * total_char)%MOD + text[i])%MOD;
		pat_hash = ((pat_hash * total_char)%MOD + pat[i])%MOD;
	}
	
	for(int i = 0; i <= text.size() - pat.size(); i++){
		if(text_hash == pat_hash)
			if(checkEqual(text , pat , i))
				ans.push_back(i);
		
		int char_value = text[i] , char_value_new = (i < (text.size() - pat.size())) ? (text[i + pat.size()]) : 0;
		text_hash = ((((text_hash - (char_value * max_power) % MOD) * total_char) % MOD) + char_value_new) % MOD;
	}
	
	cout<<"The Pattern was found in the Text at following indices -> ";
	
	for(int i=0;i<ans.size();i++)
	    cout<<ans[i]<<" ";	
}
