// Problem: B. Array
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/contest/2209/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++) {
		int x1=-inf,x2=inf;
		int c1=0,c2=0;
		for(int j=i+1;j<n;j++) {
			if (abs(a[i]-x1) > abs(a[j]-x1)) c1++;
			if (abs(a[i]-x2) > abs(a[j]-x2)) c2++;
		}
		cout<<max(c1,c2)<<" ";
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







