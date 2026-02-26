// Problem: A. Cut the Array
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/A
// Memory Limit: 512 MB
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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	
	for(int l=1;l<=n-2;l++) {
		for(int r=l+1;r<=n-1;r++) {
			if (pre[l]%3 == (pre[r]-pre[l])%3 and pre[l]%3 == (pre[n]-pre[r])%3 or 
				pre[l]%3 != (pre[r]-pre[l])%3 and pre[l]%3 != (pre[n]-pre[r])%3 and (pre[r]-pre[l])%3 != (pre[n]-pre[r])%3) {
				cout<<l<<" "<<r<<"\n";
				return;
			}
		}
	}
	cout<<"0 0\n";
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









