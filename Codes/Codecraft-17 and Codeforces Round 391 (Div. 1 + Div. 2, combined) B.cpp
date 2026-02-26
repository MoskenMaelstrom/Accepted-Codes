// Problem: B. Bash's Big Day
// Contest: Codeforces - Codecraft-17 and Codeforces Round 391 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/757/B
// Memory Limit: 512 MB
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

const int N=1e5;
void solve()
{
	map<int,int> mp;
	int n;
	cin>>n;
	vector<int> ans(N+1);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		mp[num]++;
	}
	for(int i=2;i<=N;i++) {
		for(int j=1;j*i<=N;j++) {
			if (mp.contains(i*j)) ans[i]+=mp[i*j];
		}
	}
	int maxn=1;
	for(int i=0;i<=N;i++) maxn=max(maxn,ans[i]);
	cout<<maxn;
	
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









