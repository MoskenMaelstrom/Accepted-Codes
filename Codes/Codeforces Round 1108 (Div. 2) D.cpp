// Problem: D. diss_quack and Array Game
// Contest: Codeforces - Codeforces Round 1108 (Div. 2)
// URL: https://codeforces.com/contest/2246/problem/D
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=-1;
	
	auto calc=[&](int x) -> int {
		return log2(x)+__builtin_popcount(x);
	};
	
	for(int k=0;k<=20;k++) {
		int cur=k;
		for(int i=0;i<n;i++) {
			int st=(a[i]+(1<<k)-1)>>k;
			if (st == 0) st=1;
			int minx=inf;
			for(int j=st;j<=st+20;j++) {
				int x=j*(1<<k)-a[i]+calc(j);
				if (x < minx) minx=x;
				if (j*(1<<k)-a[i]+1 >= minx) break;
			}
			cur+=minx;
		}
		if (ans == -1 or cur < ans) ans=cur;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







