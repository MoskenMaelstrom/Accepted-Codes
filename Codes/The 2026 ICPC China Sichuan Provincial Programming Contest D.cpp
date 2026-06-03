// Problem: T766535 [SCCPC 2026] 那一天的回文字符串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T766535?contestId=330287
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
	string s;
	cin>>s;
	int n=s.size();
	bool ok=1;
	vector<int> a(26),b(26);
	if (n&1) {
		for(int i=0;i<n;i++) {
			if (i&1) b[s[i]-'a']++;
			else a[s[i]-'a']++;
		}
		int c1=0,c2=0;
		for(int i=0;i<26;i++) {
			if (a[i]&1) c1++;
		}
		for(int i=0;i<26;i++) {
			if (b[i]&1) c2++;
		}
		
		if (n%4 == 1) {
			if (c1 != 1 or c2 != 0) ok=0;
		}
		else {
			if (c1 != 0 or c2 != 1) ok=0;
		}
	}
	else {
		for(int i=0;i<n;i++) {
			if (i&1) b[s[i]-'a']++;
			else a[s[i]-'a']++;
		}
		for(int i=0;i<26;i++) {
			if (a[i] != b[i]) ok=0;
		}
	}
	
	if (ok) cout<<"YES\n";
	else cout<<"NO\n";
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







