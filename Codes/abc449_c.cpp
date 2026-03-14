// Problem: C - Comfortable Distance
// Contest: AtCoder - AtCoder Beginner Contest 449
// URL: https://atcoder.jp/contests/abc449/tasks/abc449_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,l,r;
	cin>>n>>l>>r;
	vector cnt(26,vector<int>(n+1));
	string s;
	cin>>s;
	s=" "+s;
	for(int i=0;i<26;i++) {
		for(int j=1;j<=n;j++) {
			if (s[j]-'a' == i) cnt[i][j]++;
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans+=cnt[s[i]-'a'][min(n,i+r)]-cnt[s[i]-'a'][min(n,i+l-1)];
	}
	cout<<ans<<"\n";
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







