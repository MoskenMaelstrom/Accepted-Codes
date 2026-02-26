// Problem: E. Skibidus and Rizz
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/E
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int f=0;
	if (n < m) {swap(n,m);f=1;}
	if (k > max(n,m) or k < abs(n-m)) {cout<<-1<<endl;return;}
	int cnt1=k-(n-m);//开头1的数量
	for(int i=0;i<cnt1;i++) cout<<(1^f);
	m-=cnt1,n-=m;
	for(int i=0;i<m;i++) cout<<(0^f)<<(1^f);
	for(int i=0;i<n;i++) cout<<(0^f);
	cout<<endl;
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









