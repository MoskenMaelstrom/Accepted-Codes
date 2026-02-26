// Problem: H. Elimination Series Once More
// Contest: Codeforces - The 2023 ICPC Asia Xian Regional Contest (The 3rd Universal Cup. Stage 9: Xian)
// URL: https://codeforces.com/gym/105471/problem/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	vector<int> a(1<<n);
	for(int& e1 : a) cin>>e1;
	
	vector<int> ans(1<<n);
	for(int p=1;p<=n;p++) {
		int len=1<<p;
		for(int i=0;i<1<<n;i+=len) {
			vector<int> order(len);
			for(int j=i;j<i+len;j++) order[j-i]=j;
			ranges::sort(order,[&a](const int x,const int y) -> bool {
				return a[x]<a[y];
			});
			for(int j=max(0ll,len-k-1);j<len;j++) {
				if (a[order[j]] >= len) ans[order[j]]=p;
			}
		}
	}
	
	for(int& e1 : ans) cout<<e1<<" ";
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









