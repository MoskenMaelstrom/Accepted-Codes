// Problem: D - (xx)
// Contest: AtCoder - Keysight Technologies Programming Contest（AtCoder Beginner Contest 454）
// URL: https://atcoder.jp/contests/abc454/tasks/abc454_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	string s1,s2;
	cin>>s1>>s2;
	string c1,c2;
	
	for(int i=0;i<s1.size();i++) {
		int len=c1.size();
		if (s1[i] == ')' and len >= 3 and c1[len-1] == 'x' and c1[len-2] == 'x' and c1[len-3] == '(') {
			c1.pop_back();
			c1.pop_back();
			c1.pop_back();
			c1+="xx";
		}
		else c1+=s1[i];
	}
	
	for(int i=0;i<s2.size();i++) {
		int len=c2.size();
		if (s2[i] == ')' and len >= 3 and c2[len-1] == 'x' and c2[len-2] == 'x' and c2[len-3] == '(') {
			c2.pop_back();
			c2.pop_back();
			c2.pop_back();
			c2+="xx";
		}
		else c2+=s2[i];
	}
	
	// cout<<c1<<"\n"<<c2<<"\n";
	// cout<<endl;
	if (c1 == c2) cout<<"Yes\n";
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







