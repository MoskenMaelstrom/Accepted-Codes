// Problem: P3143 [USACO16OPEN] Diamond Collector S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3143
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> R(n);
	vector<int> L(n);
	for(auto &e1 : a) cin>>e1;
	if (n == 1) {cout<<1;return;}
	ranges::sort(a);
	int r=0;
	for(int i=0;i<n;i++) {
		while (a[r]-a[i] <= k and r <= n-1) r++;
		R[i]=(r-1)-i+1;
	}
	
	int l=n-1;
	for(int i=n-1;i>=0;i--) {
		while (a[i]-a[l] <= k and l >= 0) l--;
		L[i]=i-(l+1)+1;
	}
	vector<int> LL(n);
	vector<int> RR(n);
	RR[n-1]=R[n-1];
	for(int i=1;i<n;i++) LL[i]=max(LL[i-1],L[i-1]);
	for(int i=n-2;i>=0;i--) RR[i]=max(RR[i+1],R[i]);
	int ans=0;
	for(int i=1;i<n;i++) ans=max(ans,RR[i]+LL[i]);
	cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









