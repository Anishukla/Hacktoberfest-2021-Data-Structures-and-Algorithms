#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter no. of elements:";
	cin>>n;
	vector<int>v(n,0);
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
	cin>>v[i];
	int mn,mx,i;
	if(n%2==0){	
	mx=max(v[0],v[1]);
	mn=min(v[0],v[1]);
	i=2;
	}
	else
	{
	i=1;
	mx=v[0];
	mn=v[0];
	}
	for(i;i<n;i+=2)
	{
		int tmax=max(v[i],v[i+1]);
		int tmin=min(v[i],v[i+1]);
		if(mx<tmax)
		mx=tmax;
		if(mn>tmin)
		mn=tmin;
	}
	cout<<"Max:"<<mx<<endl;
	cout<<"Min:"<<mn<<endl;	
}
