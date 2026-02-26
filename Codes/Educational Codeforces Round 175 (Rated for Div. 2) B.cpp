// Problem: B. Robot Program
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,x,k;
	cin>>n>>x>>k;
	string s;
	cin>>s;
	
	int p=x;
	int t=k;
	for(int i=0;i<n;i++) {
		t--;
		if (t < 0) {cout<<0<<endl;return;}
		if (s[i] == 'L') p--;
		else p++;
		if (p == 0) break;
		if (i == n-1) {cout<<0<<endl;return;}
	}
	int cnt1=0;//L
	int cnt2=0;//R
	for(int i=0;i<n;i++) {
		if (s[i] == 'L') cnt1++;
		else cnt2++;
		if (cnt1 == cnt2) {cout<<t/(i+1)+1<<endl;return;}
	}
	cout<<1<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









