// Problem: C. Even Larger
// Contest: Codeforces - Codeforces Round 1045 (Div. 2)
// URL: https://codeforces.com/contest/2134/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans=0;
	for(int i=1;i<n;i+=2) {
		int cnt=0;
		cnt+=a[i-1];
		if (i != n-1) cnt+=a[i+1];
		if (cnt-a[i] > 0 and i != n-1) {
			ans+=cnt-a[i];
			a[i+1]-=cnt-a[i];
			if (a[i+1] < 0) a[i-1]+=a[i+1],a[i+1]=0;
		}
		else if (cnt-a[i] > 0 and i == n-1) ans+=cnt-a[i],a[i-1]-=cnt-a[i];
	}
	
	cout<<ans<<'\n';
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









