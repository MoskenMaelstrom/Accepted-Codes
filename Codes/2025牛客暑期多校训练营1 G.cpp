// Problem: Symmetry Intervals
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108298/G
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
	int len,q;
	cin>>len>>q;
	string s1;
	cin>>s1;
	while (q--) {
		int cnt=0,ans=0,a;
		string s2;
		cin>>s2>>a;
		a--;
		int n=s2.length();
		for(int i=a;i<n+a;i++) {
			if (s1[i] == s2[i-a]) cnt++,ans+=cnt;
			else cnt=0;
		}
		
		cout<<ans<<'\n';
	}
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









