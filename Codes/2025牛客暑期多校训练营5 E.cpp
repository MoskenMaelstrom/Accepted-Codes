// Problem: Mysterious XOR Operation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108302/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> cnt(n);
	int ans=0;
	
	for(int i=0;i<31;i++) {
		vector<array<int,2>> f(2);
		for(int j=0;j<n;j++) {
			int x=((a[j]>>i)&1);
			f[cnt[j]%2][x]++;
		}
		ans+=(f[0][0]*f[0][1]+f[1][1]*f[1][0])*(1<<i);
		for(int j=0;j<n;j++) cnt[j]+=((a[j]>>i)&1);
	}
	cout<<ans;
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









