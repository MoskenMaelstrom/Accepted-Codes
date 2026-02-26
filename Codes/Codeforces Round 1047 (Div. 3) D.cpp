// Problem: D. Replace with Occurrences
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/contest/2137/problem/D
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
	vector<int> b=a;
	
	ranges::sort(b);
	int pre=b[0];
	int cnt=1;
	bool ok=1;
	for(int i=1;i<n;i++) {
		if (pre == b[i]) cnt++;
		else {
			if (cnt%pre != 0) ok=0;
			cnt=1;
			pre=b[i];
		}
	}
	if (cnt%pre != 0) ok=0;
	
	vector<int> ans(n);
	vector<int> c(n+10);
	if (ok == 0) cout<<"-1\n";
	else {
		map<int,int> mp;
		int m=0;
		for(int i=0;i<n;i++) {
			if (c[a[i]]%a[i] == 0) mp[a[i]]=++m,ans[i]=m,c[a[i]]++;
			else c[a[i]]++,ans[i]=mp[a[i]];
		}
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<endl;
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









