// Problem: A. Flip Flops
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/contest/2209/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,c,k;
	cin>>n>>c>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	for(int i=0;i<n;i++) {
		if (a[i] <= c) {
			int x=min(k,c-a[i]);
			k-=x;
			a[i]+=x;
			c+=a[i];
		}
		else break;
	}
	cout<<c<<"\n";
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







