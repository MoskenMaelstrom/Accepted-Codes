// Problem: F. Yamakasi
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2121/F
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
	int n,s,x;
	cin>>n>>s>>x;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	
	map<int,int> cnt;
	int ans=0;
	int p=1;
	for(int r=1;r<=n;r++) {
		if (a[r] == x) {
			while (p <= r) {
				cnt[pre[p-1]]++;
				p++;
			}
		}
		else if (a[r] > x) cnt.clear(),p=r+1;
		
		ans+=cnt[pre[r]-s];
	}
	cout<<ans<<"\n";
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









