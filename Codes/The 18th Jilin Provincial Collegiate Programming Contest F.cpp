// Problem: F. Ever Forever
// Contest: Codeforces - The 18th Jilin Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105922/problem/F
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	int ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if (s[i] == 'e' and s[j] == 'f') ans+=j-i;
		}
	}
	cout<<ans;
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







