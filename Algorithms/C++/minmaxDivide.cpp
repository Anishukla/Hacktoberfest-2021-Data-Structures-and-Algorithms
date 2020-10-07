#include<bits/stdc++.h>
using namespace std;

struct Pair{
	int mx;
	int mn;
};
Pair maxmin(vector<int>v,int start,int end)
{
	if(start==end)
	{
		Pair p;
		p.mn=v[start];
		p.mx=v[start];
		return p;
	}
	else if(end-start==1)
	{
		Pair p;
		if(v[start]>v[end])
		{
		p.mn=v[end];
		p.mx=v[start];
		}
		else
		{
			p.mn=v[start];
		    p.mx=v[end];
		}
		return p;
	}
	else
	{
		int mid=(start+end)/2;
		Pair Lminmax=maxmin(v,start,mid);
		Pair Rminmax=maxmin(v,mid+1,end);
		Pair minmax;
		if(Lminmax.mx>Rminmax.mx)
		minmax.mx=Lminmax.mx;
		else
		minmax.mx=Rminmax.mx;
		if(Lminmax.mn>Rminmax.mn)
		minmax.mn=Rminmax.mn;
		else
		minmax.mn=Lminmax.mn;
		
		return minmax;
	}
}
int main()
{
	int n;
	cout<<"Enter no. of elements:";
	cin>>n;
	vector<int>v(n,0);
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
	cin>>v[i];
	Pair ans=maxmin(v,0,n-1);
	cout<<ans.mx<<" "<<ans.mn<<endl;
}
