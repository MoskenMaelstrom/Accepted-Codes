// Problem: 小红打舞萌
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/A
// Memory Limit: 512 MB
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
	string s1,s2;
	cin>>s1>>s2;
	int a,b;
	if (s1.back() == '+') a=stoi(s1.substr(0,s1.size()-1))*2+1;
	else a=stoi(s1)*2;
	if (s2.back() == '+') b=stoi(s2.substr(0,s2.size()-1))*2+1;
	else b=stoi(s2)*2;
	
	if (a > b) cout<<"Yes\n";
	else cout<<"No\n";
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







