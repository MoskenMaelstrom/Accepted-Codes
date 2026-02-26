// Problem: B. Heapify 1
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/B
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> mark(n+1);
	bool ok=1;
	for(int i=1;i<=n;i++) {
		if (mark[i]) continue;
		for(int j=i;j<=n;j<<=1) mark[a[j]]=1;
		for(int j=i;j<=n;j<<=1) {
			if (mark[j] == 0) ok=0;
		}
	}
	if (ok) cout<<"YES\n";
	else cout<<"NO\n";
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







