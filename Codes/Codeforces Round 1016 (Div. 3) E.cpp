// Problem: E. Min Max MEX
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	
	auto check=[&](int mid) -> bool {
		vector<bool> mark(mid+1);
		int cnt=0;
		int ok=0;
		
		for(int i=0;i<n;i++) {
			if (a[i] >= mid+1) continue;
			if (mark[a[i]]) continue;
			cnt++;
			mark[a[i]]=1;
			if (cnt == mid+1) {
				ok++;
				cnt=0;
				mark.assign(mid+1,0);
			}
		}
		if (ok >= k) return 0;
		else return 1;
	};
	
	int l=0,r=n/k,ans=-1;
	while (l <= r) {
		int mid=l+r>>1;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	
	cout<<ans<<endl;
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









