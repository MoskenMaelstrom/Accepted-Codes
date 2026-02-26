// Problem: K - Just K
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	int n,k;
	cin>>n>>k;
	vector<string> a(n);
	
	int ans=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<(1<<n);i++) {
		vector<int> cnt(26,0);
		for(int j=0;j<n;j++) {
			if ((i>>j&1) == 1) {
				int len=a[j].size();
				for(int k=0;k<len;k++) {
					cnt[a[j][k]-'a']++;
				}
			}
		}
		int c=0;
		for(auto e1 : cnt) c+=(e1 == k);
		ans=max(ans,c);
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









