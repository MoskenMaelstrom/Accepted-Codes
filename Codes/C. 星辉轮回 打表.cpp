#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n=0;
void solve()
{
	n++;
	int now=n;
	int p=1;
	int ans=1;
	while (now != 0)
	{
		if (now-p < 0) {p=1;now+=n;ans++;}
		else {now-=p++;}
	}
	cout<<n<<"   "<<ans<<endl;
}
signed main()
{
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}