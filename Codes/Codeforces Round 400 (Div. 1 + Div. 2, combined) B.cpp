// Problem: B. Sherlock and his girlfriend
// Contest: Codeforces - ICM Technex 2017 and Codeforces Round 400 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/776/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	
	vector<bool> isp(n+2,1);
	isp[0]=0;
	isp[1]=0;
	for(int i=2;i<=n+1;i++) {
		if (isp[i] == 0) continue;
		for(int j=i;j*i<=n+1;j++) isp[i*j]=0;
	}
	
	if (n > 2) cout<<"2\n";
	else cout<<"1\n";
	
	for(int i=2;i<=n+1;i++) {
		if (isp[i]) cout<<"1 ";
		else cout<<"2 ";
	}
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









