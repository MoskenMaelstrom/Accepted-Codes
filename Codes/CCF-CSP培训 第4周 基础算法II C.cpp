// Problem: C - Keys
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/C
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
	int n,m,K;
	cin>>n>>m>>K;
	vector<vector<int>> a0,a1;
	
	while (m--) {
		int N;
		cin>>N;
		vector<int> tmp(N);
		for(int i=0;i<N;i++) {cin>>tmp[i];tmp[i]--;}
		char c;
		cin>>c;
		if (c == 'o') a1.push_back(tmp);
		else a0.push_back(tmp);
	}
	
	int ans=0;
	for(int i=0;i<(1<<n);i++) {
		int ok=1;
		vector<bool> f(n);
		for(int j=0;j<n;j++) {
			if ((i>>j&1) == 1) f[j]=1;
		}
		
		for(int k=0;k<a0.size();k++) {
			int cnt=0;
			for(auto e1 : a0[k]) {
				if (f[e1]) cnt++;
			}
			if (cnt >= K) ok=0; 
		}
		
		for(int k=0;k<a1.size();k++) {
			int cnt=0;
			for(auto e1 : a1[k]) {
				if (f[e1]) cnt++;
			}
			if (cnt < K) ok=0; 
		}
		
		ans+=ok;
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









