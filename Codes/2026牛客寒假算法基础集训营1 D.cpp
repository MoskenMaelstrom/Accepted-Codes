// Problem: Sequence Coloring
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/D
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> b(n+1);
	for(int i=1;i<=n;i++) b[i]=max(b[i-1],min(n,i+a[i]));
	
	auto check=[&](int x) -> int {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if (a[i] == 0) continue;
			cnt++;
			for(int j=0;j<x;j++) {
				if (i == b[i]) break;
				i=b[i];
			}
		}
		return cnt <= k;
	};
	
	int lo=0,hi=5e5,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) hi=mid-1,res=mid;
		else lo=mid+1;
	}
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







