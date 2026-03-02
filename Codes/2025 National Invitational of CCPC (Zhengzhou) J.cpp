// Problem: J. Ring Trick
// Contest: Codeforces - 2025 National Invitational of CCPC (Zhengzhou), 2025 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105941/problem/J
// Memory Limit: 2048 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

int cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
void solve()
{
	string s;
	cin>>s;
	int ans=0;
	for(int d=0;d<26;d++) {
		int res=0;
		for(auto c : s) {
			int cur=c-'A';
			(cur+=d)%=26;
			res+=cnt[cur];
		}
		ans=max(ans,res);
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







