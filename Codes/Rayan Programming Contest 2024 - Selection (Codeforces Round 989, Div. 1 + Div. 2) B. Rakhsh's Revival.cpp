// Problem: B. Rakhsh's Revival
// Contest: Codeforces - Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	string s;
	int n,m,k;
	cin>>n>>m>>k;
	string s1(k,'1');
	cin>>s;
	int pos=0,sum=0,ans=0;
	while (pos < n){
		if (s[pos] == '0') sum++;
		else sum=0;
		if (sum == m) {
			if (pos+k-1 >= n) {ans++;break;}
			s.replace(pos,k,s1);pos+=k-1;ans++;sum=0;
		}
		pos++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}




