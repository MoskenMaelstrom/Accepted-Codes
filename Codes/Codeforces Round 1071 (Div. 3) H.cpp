// Problem: H. Blackslex and Plants
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<array<int,2>> upd(q);
	for(int i=0;i<q;i++) {
		cin>>upd[i][0]>>upd[i][1];
	}
	
	vector<int> dif(n+1),ans(n+1);
	for(int v=1;v<=n;v<<=1) {
		int w=v == 1 ? 1 : v>>1;
		fill(dif.begin(),dif.end(),0);
		for(auto [l,r] : upd) {
			int t=(r-l+1)/v;
			int L=l+v-1;
			int R=l+t*v-1;
			if (L<=n) dif[L]+=v*w;
			if (R+v<=n) dif[R+v]-=(t+1)*v*w;
			if (R+v*2<=n) dif[R+v*2]+=t*v*w;
		}
        for (int i=v;i<=n;i++) dif[i]+=dif[i-v];
        for (int i=v;i<=n;i++) dif[i]+=dif[i-v];
        for (int i=1;i<=n;i++) ans[i]+=dif[i];
	}
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







