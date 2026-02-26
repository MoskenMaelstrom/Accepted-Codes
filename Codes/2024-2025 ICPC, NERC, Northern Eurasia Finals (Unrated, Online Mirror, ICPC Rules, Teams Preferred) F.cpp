// Problem: F. Fix Flooded Floor
// Contest: Codeforces - 2024-2025 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)2024-2025 ICPC, NERC, 北欧亚地区决赛（未评级，在线镜像，ICPC 规则，优先考虑团队）
// URL: https://codeforces.com/problemset/problem/2052/F
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n,vector<char>(2));
	for(int i=0;i<2;i++) {
		for(int j=0;j<n;j++) cin>>a[j][i];
	}
	int flag=0;
	for(int i=0;i<n;i++) {
		//都是#
		if (a[i][0] == '#' and a[i][1] == '#') continue;
		//其中一个是#
		else if (a[i][0] == '.' and a[i][1] == '#') {
			if (i != n-1 and a[i+1][0] == '.') a[i][0]='#',a[i+1][0]='#';
			else {cout<<"None\n";return;}
		}
		else if (a[i][0] == '#' and a[i][1] == '.') {
			if (i != n-1 and a[i+1][1] == '.') a[i][1]='#',a[i+1][1]='#';
			else {cout<<"None\n";return;}
		}
		
		//全是.
		else if (a[i][0] == '.' and a[i][1] == '.') {
			if (i != n-1 and a[i+1][0] == '.' and a[i+1][1] == '.') flag=1;
			a[i][0]='#',a[i][1]='#';
		}
	}
	if (flag) cout<<"Multiple\n";
	else cout<<"Unique\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









