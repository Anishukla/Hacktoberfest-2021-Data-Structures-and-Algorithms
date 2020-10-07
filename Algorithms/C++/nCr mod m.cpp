#include<bits/stdc++.h>
using namespace std;

//using long long instead of int increases the range of n for which the code works
#define ll long long int  

/* nCr means the number of ways to choose r objects from n given objects
    Since the value of nCr can be quite big we often calculate nCr % m , where m is generally prime 
    To simply calculate nCr , take m =1 */

ll powlm(ll a , ll b , ll m)
{
	//Calculation of (a^b)%m using recursion
    if(a==1 || b==0)
	return 1;
	else if(b%2==0)
	return powll((a*a)%m,b/2,m);
	else
	return (a*powll((a*a)%m,b/2,m))%m;
}

//only for mod by prime
ll modinv(ll n, ll m) 
{ 
    /* 
    From Fermet's Little principle , we have 
    a^-1 =(a^(m-2))%(m) 
    This happens only when m is prime
    */ 
    return powll(n, m - 2, m); 
}

ll fact[10000010];// A table of factorials till 10^7

void build_factorials()
{
    fact[1]=1;
    // Calculation of Factorial using memoization
    for(ll i=2;i<10000001;i++)
    fact[i]=fact[i-1]*i;
}
ll nCr(ll n , ll r , ll m)
{
    // nC0 = 1 i.e. the no. of ways of choosing 0 objects from n objects is 1 
	if (r == 0) 
        return 1; 
        
    /* 
    Calculation of nCr using the formula 
    nCr = n! / ( r! * (n-r)! )
    
    For the calculation of nCr % m we also use modulus identities in the above formula , as shown below 
    */
    return (fact[n] * ( modinv(fact[r], m) % m ) * ( modinv(fact[n - r], m) % m )  ) % m; 
} 

int main()
{
    build_factorials();
    
    ll n,r,mod;
    cin>>n>>r>>mod;
    cout<<nCr(n,r,mod);
    return 0;
}