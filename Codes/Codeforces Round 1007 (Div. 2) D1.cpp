// Problem: D1. Infinite Sequence (Easy Version)
// Contest: Codeforces - Codeforces Round 1007 (Div. 2)
// URL: https://codeforces.com/contest/2071/problem/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,l,r;
vector<int> a,b;

int work(int x)
{
	if (x <= n) return a[x];
	else if (x/2 <= n) return b[x/2];
	else if ((x/2)%2 == 1) return b[n];
	else return (b[n]^work(x/2));
}

void solve()
{
	cin>>n>>l>>r;
	if (n % 2 == 1) {
		a.assign(n+1,0);
		b.assign(n+1,0);
		for(int i=1;i<=n;i++) cin>>a[i];
	}
	else {
		n++;
		a.assign(n+1,0);
		b.assign(n+1,0);
		for(int i=1;i<=n-1;i++) cin>>a[i];
		int t=0;
		for(int i=1;i<=n/2;i++) t^=a[i];
		a[n]=t;
	}
	
	
	
	for(int i=1;i<=n;i++) {
		b[i]=b[i-1]^a[i];
	}
	
	cout<<work(l)<<endl;
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









