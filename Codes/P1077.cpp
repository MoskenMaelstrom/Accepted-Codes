// Problem: P1077 [NOIP 2012 普及组] 摆花
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1077
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
using namespace std;

const int p=1e6+7;
void solve()
{
	int n,m;
	int cnt=0;
	cin>>n>>m;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	map<array<int,2>,int> mp;//{pos,deep}; 
	
	auto dfs=[&](auto self,int x,int deep) -> int {
		if (mp[{x,deep}] == -1) return 0;
		else if (mp[{x,deep}] != 0) return mp[{x,deep}];
		
		if (deep == m) {
			mp[{x,deep}]=1;
			return 1;
		}
		if (deep > m or x == n-1) {
			mp[{x,deep}]=-1;
			return 0;
		}
		
		int sum=0;
		for(int i=0;i<=a[x+1];i++) {
			sum+=self(self,x+1,deep+i);
			sum%=p;
		}
		mp[{x,deep}]=sum;
		return sum;
	};
	
	for(int i=0;i<=a[0];i++) {
		cnt+=dfs(dfs,0,i);
		cnt%=p;
	}
	cout<<cnt;
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









