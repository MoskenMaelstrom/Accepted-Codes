// Problem: P2580 于是他错误的点名开始了
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2580
// Memory Limit: 128 MB
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
	map<string,int> mp;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		mp[s]=1;
	}
	
	int q;
	cin>>q;
	while (q--) {
		string s;
		cin>>s;
		if (mp.count(s) == 0) cout<<"WRONG\n";
		else if (mp[s] == 1) {
			cout<<"OK\n";
			mp[s]++;
		}
		else cout<<"REPEAT\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







