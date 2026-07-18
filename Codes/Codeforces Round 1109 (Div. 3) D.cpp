// Problem: D. Yaroslav and Productivity
// Contest: Codeforces - Codeforces Round 1109 (Div. 3)
// URL: https://codeforces.com/contest/2244/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> b(m+1);
	for(int i=1;i<=m;i++) cin>>b[i];
	ranges::sort(b);
	
	int ans=0;
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int cur=1;
	for(int i=1;i<=m;i++) {
		int x=pre[b[i]]-pre[cur-1];
		ans+=abs(x);
		cur=b[i]+1;
	}
	if (cur != n+1) {
		ans+=pre[n]-pre[cur-1];
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







