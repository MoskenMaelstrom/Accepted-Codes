// Problem: F. A Bit Odd
// Contest: Codeforces - Codeforces Round 1107 (Div. 3)
// URL: https://codeforces.com/contest/2241/problem/F
// Memory Limit: 256 MB
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
	// 某一个0前面有奇数个1
	// 某一个1后面有奇数个0
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	s="0"+s;
	vector<int> pre1(n+2),suf0(n+2);
	for(int i=1;i<=n;i++) {
		pre1[i]=pre1[i-1]+(s[i] == '1');
	}
	for(int i=n;i>=1;i--) {
		suf0[i]=suf0[i+1]+(s[i] == '0');
	}
	
	bool ok=0;
	for(int i=1;i<=n;i++) {
		if (s[i] == '1' and suf0[i]&1) ok=1;
		if (s[i] == '0' and pre1[i]&1) ok=1;
	}
	
	if (ok) cout<<"Alice\n";
	else cout<<"Bob\n";
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







