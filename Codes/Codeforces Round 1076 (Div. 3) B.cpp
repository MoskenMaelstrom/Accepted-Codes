// Problem: B. Reverse a Permutation
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/B
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++) {
		if (n-i != a[i]) {
			for(int j=i+1;j<n;j++) {
				if (a[j] == n-i) {
					for(int k=0;k<i;k++) cout<<a[k]<<" ";
					for(int k=j;k>=i;k--) cout<<a[k]<<" ";
					for(int k=j+1;k<n;k++) cout<<a[k]<<" ";
					cout<<"\n";
					return;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
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







