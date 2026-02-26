// Problem: F. Minimize Fixed Points
// Contest: Codeforces - Codeforces Round 1034 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2123/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<bool> mark(n+1);
	ranges::iota(a,0);
	mark[1]=1;
	
	for(int i=n;i>=2;i--) {
		for(int j=2;i*j<=n;j++) {
			if (mark[i*j] == 0) {
				swap(a[i],a[i*j]);
				mark[i]=1;
				mark[i*j]=1;
			}
		}
		if (mark[i] == 0) {
			for(int j=2;i*j<=n;j++) {
				if (gcd(a[i],a[i*j]) > 1) {
					swap(a[i],a[i*j]);	
					mark[i]=1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<'\n';
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









