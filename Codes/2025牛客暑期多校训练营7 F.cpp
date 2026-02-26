// Problem: The Correlation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108304/F
// Memory Limit: 2048 MB
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

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	int c1=0,c2=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i]%2) c1++;
		else c2++;
	}
	
	cout<<(c1*c2+p)%p<<'\n';
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









