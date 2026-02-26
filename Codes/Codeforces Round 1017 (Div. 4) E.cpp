// Problem: E. Boneca Ambalabu
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/E
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt[31] {};
	for(int i=0;i<n;i++) {
		for(int j=0;j<=30;j++) {
			cnt[j]+=a[i]>>j&1;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		int cur=0;
		for(int j=0;j<=30;j++) {
			if ((a[i]>>j&1) == 0) cur+=cnt[j]*(1ll<<j);
			else cur+=(n-cnt[j])*(1ll<<j);
		}
		ans=max(cur,ans);
	}
	cout<<ans<<endl;
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









