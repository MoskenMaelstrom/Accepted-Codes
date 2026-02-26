// Problem: E - Cookies
// Contest: AtCoder - AtCoder Beginner Contest 440
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_e
// Memory Limit: 1024 MB
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
	int n,k,x;
	cin>>n>>k>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	priority_queue<array<int,3>,vector<array<int,3>>> pq;
	
	pq.push({k*a[n-1],k,n-2});
	while (x--) {
		auto [ans,cnt,p]=pq.top();
		pq.pop();
		cout<<ans<<"\n";
		if (cnt == 0) continue;
		for(int i=0;i<=p;i++) {
			pq.push({ans-a[n-1]+a[i],cnt-1,i});
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







