// Problem: E. Binary Wine
// Contest: Codeforces - Codeforces Round 1064 (Div. 2)
// URL: https://codeforces.com/contest/2166/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<32;i++) a.push_back(0);
	ranges::sort(a,greater<int>());
	a.resize(32);
	n=32;
	
	while (q--) {
		int c;
		cin>>c;
		int cost=0;
		multiset<int,greater<int>> st(a.begin(),a.end());
		for(int b=29;b>=0;b--) {
			if (((c>>b)&1) == 1) {
				int x=*st.begin();
				st.erase(st.begin());
				if (x >= (1 << (b+1))) {
					break;
				}
				else if (x&(1<<b)) {
					x-=(1<<b);
					st.insert(x);
					c-=(1<<b);
				}
				else {
					cost+=(1<<b)-x;
					c-=(1<<b);
				}
			}
		}
		cout<<cost<<"\n";
	}
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







