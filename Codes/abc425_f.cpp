// Problem: F - Inserting Process
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_f
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
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

const int p=998244353;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		char c;
		cin>>c;
		a[i]=c-'a';
	}
	
	vector<int> dp(1<<n);
	dp[(1<<n)-1]=1;
	for(int i=(1<<n)-1;i>=0;i--) {
		for(int k=0;k<n;k++) {
			if (i&(1<<k)) {
				int lst=k-1;
				while (lst != -1 and (i&(1<<lst)) == 0) lst--;
				if (lst != -1 and a[lst] == a[k]) continue;
				dp[i-(1<<k)]+=dp[i];
				dp[i-(1<<k)]%=p;
			}
		}
	}
	cout<<dp[0];
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









