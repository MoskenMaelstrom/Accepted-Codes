// Problem: C - Variety Split Easy
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_c
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	vector<int> dp1(n),dp2(n);//n-1不用
	set<int> st1,st2;
	for(int i=0;i<n-1;i++) {
		if (st1.find(a[i]) == st1.end()) st1.insert(a[i]);
		else dp1[i]++;
	}
	for(int i=n-1;i>=1;i--) {
		if (st2.find(a[i]) == st2.end()) st2.insert(a[i]);
		else dp2[i-1]++;
	}
	for(int i=1;i<n;i++) dp1[i]+=dp1[i-1];
	for(int i=n-2;i>=0;i--) dp2[i]+=dp2[i+1];
	// for(auto e1 : dp1) cout<<e1<<" ";
	// cout<<endl;
	// for(auto e1 : dp2) cout<<e1<<" ";
	
	int ans=1000000;
	for(int i=0;i<n-1;i++) {
		int cur=dp1[i]+dp2[i];
		ans=min(ans,cur);
	}
	cout<<n-ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









