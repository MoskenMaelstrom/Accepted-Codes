// Problem: D - Sum of Differences
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Christmas (AtCoder Beginner Contest 437)
// URL: https://atcoder.jp/contests/abc437/tasks/abc437_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=998244353;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> b(m+1);
	for(int i=1;i<=m;i++) cin>>b[i];
	
	sort(b.begin()+1,b.end());
	vector<int> preb(m+1);
	int ans=0;
	for(int i=1;i<=m;i++) preb[i]=preb[i-1]+b[i],preb[i]%=p;
	
	for(int i=1;i<=n;i++) {
		int k=upper_bound(b.begin()+1,b.end(),a[i])-b.begin()-1;
		ans+=preb[m]-2*preb[k]+(2*k-m)*a[i],ans%=p;
	}
	cout<<(ans+p)%p;
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







