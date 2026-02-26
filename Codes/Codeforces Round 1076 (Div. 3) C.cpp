// Problem: C. Replace and Sum
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/C
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		int num;
		cin>>num;
		a[i]=max(a[i],num);
	}
	for(int i=n-1;i>=1;i--) a[i]=max(a[i],a[i+1]);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	while (q--) {
		int l,r;
		cin>>l>>r;
		cout<<a[r]-a[l-1]<<" ";
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







