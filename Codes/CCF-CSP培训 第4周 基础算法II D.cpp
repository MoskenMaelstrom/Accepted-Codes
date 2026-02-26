// Problem: D - Festival
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/D
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
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	for(int i=0;i<m;i++) cin>>a[i];
	
	vector<int> vec(n+1);
	vec[n]=1;
	for(int i=0;i<m;i++) {
		vec[a[i]]=1;
	}
	
	vector<int> ans(n+1);
	ans[n]=0;
	int cur=n;
	for(int i=n-1;i>=1;i--) {
		if (vec[i] == 1) cur=i;
		ans[i]=cur-i;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
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









