// Problem: C. Fox and Card Game
// Contest: Codeforces - Codeforces Round 228 (Div. 1)
// URL: https://codeforces.com/problemset/problem/388/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector a(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		int m;
		cin>>m;
		while (m--) {
			int num;
			cin>>num;
			a[i].push_back(num);
		}
	}
	
	ranges::sort(a,[](const vector<int>& x,const vector<int>& y) -> bool {
		if (x.size()%2 == 0 and y.size()%2 != 0) return 1;
		if (x.size()%2 != 0 and y.size()%2 != 0) {
			return (x[x.size()/2] > y[y.size()/2]);
		}
		return 0;
	});
	
	int c0=0,c1=0,f=0;
	for(int i=0;i<n;i++) {
		auto& b=a[i];
		int m=b.size();
		if (m%2 == 0) {
			for(int i=0;i<m/2;i++) c0+=b[i];
			for(int i=m/2;i<m;i++) c1+=b[i];
		}
		else {
			if (f) {
				for(int i=0;i<m/2;i++) c0+=b[i];
				for(int i=m/2;i<m;i++) c1+=b[i];
			}
			else {
				for(int i=0;i<=m/2;i++) c0+=b[i];
				for(int i=m/2+1;i<m;i++) c1+=b[i];
			}
			f=1-f;
		}
	}
	cout<<c0<<" "<<c1<<"\n";
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









