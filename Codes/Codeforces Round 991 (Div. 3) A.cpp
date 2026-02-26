#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int n,m,ans=0;
	int len[55];
	cin>>n>>m;
	string s;
	rep(i,n){
		cin>>s;
		len[i]=s.length();
	}
	rep(i,n){
		if (m-len[i] >= 0) {ans++;m-=len[i];}
		else break;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}