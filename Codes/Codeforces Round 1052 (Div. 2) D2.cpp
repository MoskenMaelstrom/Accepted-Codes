// Problem: D2. Max Sum OR (Hard Version)
// Contest: Codeforces - Codeforces Round 1052 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2146/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int l,r;
	cin>>l>>r;
	int n=r-l+1;
	vector<int> a(n,-1);
	for(int k=30;k>=0;k--) {
		int all=(1<<k)-1;
		for(int i=0;i<n;i++) {
			if (a[i] != -1) continue;
			int j=(all^(i+l))-l;
			if (j < 0 or j >= n or a[j] != -1) continue;
			a[i]=j,a[j]=i;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) ans+=(a[i]+l)|(i+l);
	cout<<ans<<"\n";
	for(auto e1 : a) cout<<e1+l<<" ";
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







