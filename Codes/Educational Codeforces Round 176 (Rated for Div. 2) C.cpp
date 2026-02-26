// Problem: C. Two Colors
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://mirror.codeforces.com/contest/2075/problem/C
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
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	for(auto &e1 : a) cin>>e1;
	ranges::sort(a);
	const int N=n+5;
	vector<int> cnt(N);
	for(int i=1;i<=n-1;i++) {
		int num=m-(lower_bound(a.begin(),a.end(),i)-a.begin());
		cnt[i]=num;
	}
	
	int ans=0;
	for(int i=1;i<=n/2;i++) {
		if (i != n-i) ans+=((cnt[i]-1)*cnt[n-i])*2;
		else ans+=((cnt[i]-1)*cnt[n-i]);
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









