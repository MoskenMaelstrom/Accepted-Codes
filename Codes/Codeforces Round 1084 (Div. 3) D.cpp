// Problem: D. Portal
// Contest: Codeforces - Codeforces Round 1084 (Div. 3)
// URL: https://codeforces.com/contest/2200/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> b(y-x);
	for(int i=x;i<y;i++) {
		b[i-x]=a[i];
	}
	
	int p=ranges::min_element(b)-b.begin();
	vector<int> c(y-x);
	for(int i=0;i<y-x;i++) {
		c[i]=b[(i+p)%(y-x)];
	}
	
	vector<int> d;
	for(int i=0;i<n;i++) {
		if (i >= x and i < y) continue;
		d.push_back(a[i]);
	}
	
	int ok=1;
	for(int i=0;i<n-y+x;i++) {
		if (ok and d[i] > *c.begin()) {
			for(auto e1 : c) cout<<e1<<" ";
			ok=0;
		}
		cout<<d[i]<<" ";
	}
	if (ok) {
		for(auto e1 : c) cout<<e1<<" ";
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







