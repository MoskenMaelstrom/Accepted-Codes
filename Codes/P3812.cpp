// Problem: P3812 【模板】线性基
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3812
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> B(61);
	auto insert=[&](int x) {
		for(int i=60;i>=0;i--) {
			if ((x>>i)&1) {
				if (B[i]) x^=B[i];
				else {B[i]=x;return;}
			}
		}
	};
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		insert(x);
	}
	int ans=0;
	for(int i=60;i>=0;i--) {
		if ((ans^(B[i])) > ans) ans^=B[i];
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







