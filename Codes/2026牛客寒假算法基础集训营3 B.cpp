// Problem: Random
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/B
// Memory Limit: 512 MB
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
		for(int j=1;j<200;j++) {
			if (i+j >= n) break;
			if (gcd(a[i],a[i+j]) != 1) {
				cout<<a[i]<<" "<<a[i+j]<<"\n";
				return;
			}
		}
	}
	cout<<"-1\n";
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







