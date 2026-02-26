// Problem: P2392 kkksc03考前临时抱佛脚
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2392
// Memory Limit: 125 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n1,n2,n3,n4;
	cin>>n1>>n2>>n3>>n4;
	vector<int> a1(n1),a2(n2),a3(n3),a4(n4);
	for(auto &e1 : a1) cin>>e1;
	for(auto &e1 : a2) cin>>e1;
	for(auto &e1 : a3) cin>>e1;
	for(auto &e1 : a4) cin>>e1;
	
	vector<int> a;
	auto bag=[&]() -> int {
		int n=a.size();
		int sum=0;
		for(int i=0;i<n;i++) {
			sum+=a[i];
		}
		int T=sum/2;
		vector<int> dp(T+1);
		
		
		for(int i=0;i<n;i++) {
			for(int j=T;j>=a[i];j--) {
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		}
		return sum-dp[T];
	};
	int ans=0;
	a=a1;
	ans+=bag();
	a=a2;
	ans+=bag();
	a=a3;
	ans+=bag();
	a=a4;
	ans+=bag();
	
	cout<<ans;
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









