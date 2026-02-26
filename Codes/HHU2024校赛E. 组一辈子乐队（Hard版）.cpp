#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while (t--)
	{
		double r,B,C;
		cin>>r>>B>>C;
		r/=100;
		cout<<(r+1)*B/r/r+C/r<<endl;
	}
	
	return 0;
}










