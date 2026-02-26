// Problem: C2. Shohag Loves XOR (Hard Version)
// Contest: Codeforces - CodeTON Round 9 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/2039/problem/C2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int x,m,y,ans=0,t0=-1;
	cin>>x>>m;
	if (x == 1) {cout<<m<<endl;return;}
	if (m<=2*x or x <=100 and m<=10000) {
		for(int i=1;i<=m;i++) {
			y=i;
			int t=x^y;
			if (t%x == 0 or t%y == 0) ans++;
		}
		cout<<ans<<endl;
		return;
	}
	
	
	for(int i=1;i<=x;i++) {
		y=i;
		int t=x^y;
		if (t%x == 0 or t%y == 0) ans++;
	}
	//找到枚举的t的最大值
	int find=0;
		for(int i=m;i>=1;i--) {
		y=i;
		int t=x^y;
		if ((t%x == 0 or t%y == 0) and find<=5) {
			t0=max(t0,t);
			find++;
		}
		if (find == 5) break;
	}
	//此时的t0为最大的t0,后半部分的ans为(t0-2x)/x+1
	ans+=(t0-2*x)/x+1;//此时的ans还是满打满算的，可能t0-若干x的不存在，要往后找
	find=0;
	for(int i=m;i>=1;i++) {
		y=i;
		int t=x^y;
		if ((t%x == 0 or t%y == 0) and find<=5) {
			if (t == t0-x) ans--;
			if (t == t0-2*x) ans--;
			if (t == t0-3*x) ans--;
			if (t == t0-4*x) ans--;
			if (t == t0-5*x) ans--;
			find++;
		}
		if (find == 5) break;
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