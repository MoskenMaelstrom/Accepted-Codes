// Problem: D. Me When Median Problem
// Contest: Codeforces - Spectral::Cup 2026 Round 2 (Codeforces Round 1100, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2229/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	auto check=[&](int x) {
		int c2=0,c0=0;
		bool f=0;
		for(int i=0;i<n;i++) {
			int cnt=(a[i] >= x)+(b[i] >= x);
			if (cnt == 2) {
				c2++;
				f=0;
			}
			else if (cnt == 0 and !f) {
				c0++;
				f=1;
			}
		}
		return c2 > c0;
	};
	
	int lo=1,hi=2*n,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,lo=mid+1;
		else hi=mid-1;
	}
	assert(res != -1);
	cout<<res<<"\n";
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







