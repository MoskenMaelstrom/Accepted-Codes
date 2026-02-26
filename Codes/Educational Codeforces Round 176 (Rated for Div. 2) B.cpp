// Problem: B. Array Recoloring
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://mirror.codeforces.com/contest/2075/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	vector b=a;
	ranges::sort(a);
	ranges::reverse(a);
	
	int ans=0;
	int maxn=a[0];
	if (k != 1) {
		for(int i=0;i<=k;i++) ans+=a[i];
	}
	else {
		if (b[0] == maxn or b[n-1] == maxn) ans=a[0]+a[1];
		else ans=a[0]+max(b[0],b[n-1]);
	}
	
	cout<<ans<<endl;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









