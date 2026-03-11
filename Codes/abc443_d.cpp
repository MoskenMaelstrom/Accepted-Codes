// Problem: D - Pawn Line
// Contest: AtCoder - Denso Create Programming Contest 2026（AtCoder Beginner Contest 443）
// URL: https://atcoder.jp/contests/abc443/tasks/abc443_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i],a[i]=n-a[i];
	priority_queue<array<int,2>> pq;
	for(int i=0;i<n;i++) pq.push({a[i],i});
	int ans=0;
	while (!pq.empty()) {
		auto [val,id]=pq.top();
		pq.pop();
		if (id-1 >= 0 and a[id]-a[id-1] > 1) {
			ans+=a[id]-a[id-1]-1;
			a[id-1]=a[id]-1;
			pq.push({a[id-1],id-1});
		}
		if (id+1 <= n-1 and a[id]-a[id+1] > 1) {
			ans+=a[id]-a[id+1]-1;
			a[id+1]=a[id]-1;
			pq.push({a[id+1],id+1});
		}
	}
	cout<<ans<<"\n";
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







