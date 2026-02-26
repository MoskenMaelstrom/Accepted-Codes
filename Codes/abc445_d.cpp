// Problem: D - Reconstruct Chocolate
// Contest: AtCoder - AtCoder Beginner Contest 445
// URL: https://atcoder.jp/contests/abc445/tasks/abc445_d
// Memory Limit: 1024 MB
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
	int H,W,n;
	cin>>H>>W>>n;
	vector<int> h(n),w(n);
	for(int i=0;i<n;i++) cin>>h[i]>>w[i];
	vector<int> ph(n),pw(n);
	
	ranges::iota(ph,0);
	ranges::sort(ph,[&](int i,int j) {
		return h[i] > h[j];
	});
	
	ranges::iota(pw,0);
	ranges::sort(pw,[&](int i,int j) {
		return w[i] > w[j];
	});
	
	vector<int> vis(n),x(n),y(n);
	int i=0,j=0;
	while (i < n) {
		if (h[ph[i]] == H) {
			int u=ph[i];
			vis[u]=1;
			x[u]=1;
			y[u]=W-w[u]+1;
			W-=w[u];
		}
		else {
			int u=pw[j];
			vis[u]=1;
			y[u]=1;
			x[u]=H-h[u]+1;
			H-=h[u];
		}
		while (i < n and vis[ph[i]]) i++;
		while (j < n and vis[pw[j]]) j++;
	}
	for(int i=0;i<n;i++) {
		cout<<x[i]<<" "<<y[i]<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







