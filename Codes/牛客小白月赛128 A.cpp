// Problem: 模糊匹配
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/A
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
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++) {
		if (s1[i] == '0') s1[i]='O';
		if (s2[i] == '0') s2[i]='O';
		if (s1[i] == 'l' or s1[i] == 'I') s1[i]='1';
		if (s2[i] == 'l' or s2[i] == 'I') s2[i]='1';
	}
	// cout<<s1<<" "<<s2<<"\n";
	if (s1 == s2) cout<<"YES\n";
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







