// Problem: 比赛安排（PDF题面存放于本题）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/A
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if (abs(a-b) < 2 and abs(a-c) < 2 and abs(b-c) < 2) cout<<"YES\n";
	else cout<<"NO\n";
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







