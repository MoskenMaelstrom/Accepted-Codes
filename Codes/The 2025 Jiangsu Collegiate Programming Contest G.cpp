// Problem: G. Monetary System
// Contest: Codeforces - The 2025 Jiangsu Collegiate Programming Contest, The 2025 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105945/problem/G
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> b(a[n-1]+1);
	for(int i=1;i<=a[n-1];i++) {
		b[i]=b[i-a[ranges::upper_bound(a,i)-a.begin()-1]]+1;
	}
	ranges::sort(b);
	while (q--) {
		int x;
		cin>>x;
		cout<<ranges::upper_bound(b,x)-b.begin()-1<<" ";
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







