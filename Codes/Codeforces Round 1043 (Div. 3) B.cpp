// Problem: B. The Secret Number
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/B
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector<int> ans;
	for(int i=1,p=10;p<=n;i++,p*=10) {
		int d=1+p;
		if (n%d == 0) ans.push_back(n/d);
	}
	
	if (ans.size() == 0) {cout<<ans.size()<<'\n';return;}
	cout<<ans.size()<<'\n';
	ranges::sort(ans);
	for(auto e1 : ans) cout<<e1<<' ';
	cout<<'\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









