// Problem: T766539 [SCCPC 2026] 最大权独立集问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T766539?contestId=330287
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int c1=0,c2=0;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		int c=__builtin_popcountll(num);
		if (c&1) c1+=num;
		else c2+=num;
	}
	cout<<max(c1,c2)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







