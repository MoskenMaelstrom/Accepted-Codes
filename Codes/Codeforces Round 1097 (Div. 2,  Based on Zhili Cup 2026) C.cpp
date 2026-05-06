// Problem: C. Zhily and Bracket Swapping
// Contest: Codeforces - Codeforces Round 1097 (Div. 2,  Based on Zhili Cup 2026)
// URL: https://codeforces.com/contest/2224/problem/C
// Memory Limit: 512 MB
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
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int c1=0,c2=0;
	for(int i=0;i<n;i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] == '(') c1++,c2++;
			else c1--,c2--;
		}
		else {
			if (c1 < c2) {
				s1[i]='(';
				s2[i]=')';
				c1++,c2--;
			}
			else {
				s1[i]=')';
				s2[i]='(';
				c1--,c2++;
			}
		}
	}
	
	c1=0,c2=0;
	bool ok=1;
	for(int i=0;i<n;i++) {
		if (s1[i] == '(') c1++;
		else c1--;
		if (s2[i] == '(') c2++;
		else c2--;
		if (c1 < 0 or c2 < 0) ok=0;
	}
	if (c1 != 0 or c2 != 0) ok=0;
	
	if (ok) cout<<"YES\n";
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







