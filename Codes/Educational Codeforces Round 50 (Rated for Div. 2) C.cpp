// Problem: C. Classy Numbers
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1036/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int work(int x) {
	if (x == 0) return 1;
	vector<int> a;
	while (x) {
		a.push_back(x%10);
		x/=10;
	}
	
	vector dp(20,vector<int>(4,-1));
	function<int(int,int,int)> dfs=[&](int pos,int cnt,bool limit) -> int {
		if (cnt > 3) return 0;
		if (pos == -1) return 1;
		if (limit == 0 and dp[pos][cnt] != -1) return dp[pos][cnt];
		
		int res=0;
		int up=limit ? a[pos] : 9;
		for(int i=0;i<=up;i++) {
			res+=dfs(pos-1,cnt+(i != 0),limit and (i == up));
		}
		if (limit == 0) dp[pos][cnt]=res;
		return res;
	};
	return dfs(a.size()-1,0,1);
}

void solve()
{
	int l,r;
	cin>>l>>r;
	cout<<work(r)-work(l-1)<<"\n";
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







