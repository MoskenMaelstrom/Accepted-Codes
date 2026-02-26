// Problem: Inverted World
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	string s1,s2;
	for(int i=0;i<n;i++) {
		if (i&1) {
			if (s[i] != '0') s1+=s[i];
		}
		else {
			if (s[i] != '1') s1+=s[i];
		}
	}
	for(int i=0;i<n;i++) {
		if (i&1) {
			if (s[i] == '0') s2+=s[i];
		}
		else {
			if (s[i] == '1') s2+=s[i];
		}
	}
	
	auto calc=[&](string S) -> int {
		if (S.empty()) return 0;
		int c0=0,c1=0;
		for(int i=0;i<S.size();i++) {
			if (S[i] == '0') {
				if (c1 != 0) c1--,c0++;
				else c0++;
			}
			else {
				if (c0 != 0) c0--,c1++;
				else c1++;
			}
		}
		return c0+c1;
	};
	
	cout<<min(calc(s1),calc(s2))<<"\n";
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







