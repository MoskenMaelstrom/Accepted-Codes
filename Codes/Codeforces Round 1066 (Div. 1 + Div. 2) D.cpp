// Problem: D. Billion Players Game
// Contest: Codeforces - Codeforces Round 1066 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2157/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	
	int ans=0;
	int L=0,R=n-1;
	while (L < R) {
		if (a[L] <= l and a[R] <= l) ans+=2*l-a[L]-a[R];
		else if (a[L] >= r and a[R] >= r) ans+=a[L]+a[R]-2*r;
		else ans+=a[R]-a[L];
		L++,R--;
	}
	if (L == R) {
		if (a[L] < l) ans+=l-a[L];
		if (a[R] > r) ans+=a[R]-r;
	}
	cout<<ans<<"\n";
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







