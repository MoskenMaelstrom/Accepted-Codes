// Problem: D. Division Versus Addition
// Contest: Codeforces - Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2152/D
// Memory Limit: 1024 MB
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> ans(n+1);
	vector<int> n1(n+1),n2(n+1);
	vector<int> ok(n+1);
	for(int i=1;i<=n;i++) {
		int cnt=0,num=a[i];
		while (num != 1) {
			cnt+=(num&1);
			num>>=1;
			ans[i]++;
		}
		if (cnt == 1 and (a[i]&1) == 1) ok[i]++;
		if (cnt == 1) n1[i]++;
		if (cnt >= 2) n2[i]++;
		n1[i]+=n1[i-1];
		n2[i]+=n2[i-1];
		ans[i]+=ans[i-1];
		ok[i]+=ok[i-1];
	}
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		int c1=n1[r]-n1[l-1];
		int c2=n2[r]-n2[l-1];
		
		c1-=ok[r]-ok[l-1]+1>>1;
		cout<<ans[r]-ans[l-1]+c1+c2<<"\n";
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









