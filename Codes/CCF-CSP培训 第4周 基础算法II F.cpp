// Problem: F - Count xxx
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/F
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(26);
	int c=0;
	for(int i=0;i<n;i++) {
		if (i and s[i] != s[i-1]) c=0;
		c++;
		a[s[i]-'a']=max(a[s[i]-'a'],c);
	}
	int ans=0;
	for(auto e1 : a) ans+=e1;
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









