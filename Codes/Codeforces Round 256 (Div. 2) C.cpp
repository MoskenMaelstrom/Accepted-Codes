// Problem: C. Painting Fence
// Contest: Codeforces - Codeforces Round 256 (Div. 2)
// URL: https://codeforces.com/problemset/problem/448/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector dp(n,vector<int>(n,inf));
	function<int(int,int)> dfs=[&](int l,int r) -> int {
		if (l > r) return 0;
		int id=min_element(a.begin()+l,a.begin()+r+1)-a.begin();
		int w=a[id];
		for(int i=l;i<=r;i++) a[i]-=w;
		return min(r-l+1,w+dfs(l,id-1)+dfs(id+1,r));
	};
	cout<<dfs(0,n-1);
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







