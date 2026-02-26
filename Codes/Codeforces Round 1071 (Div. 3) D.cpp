// Problem: D. Blackslex and Penguin Civilization
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/D
// Memory Limit: 256 MB
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
	map<int,int> mp;
	cout<<(1<<n)-1<<" ";
	for(int i=n-1;i>0;i--) {
		int num=(1<<i)-1;
		for(int j=0;j<1<<(n-i-1);j++) {
			cout<<(j<<(i+1))+num<<" ";
			mp[(j<<(i+1))+num]=1;
		}
	}
	for(int i=0;i<(1<<n)-1;i++) {
		if (mp.count(i)) continue;
		else cout<<i<<" ";
	}
	cout<<"\n";
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







