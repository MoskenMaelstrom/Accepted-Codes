// Problem: E. Unpleasant Strings
// Contest: Codeforces - Educational Codeforces Round 178 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2104/E
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

const int inf=1e18;
void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s="a"+s;
	
	vector nxt(n+1,vector<int>(k,n+1));
	vector<int> lst(k,n+1);
	for(int i=n;i>=0;i--) {
		for(int j=0;j<k;j++) {
			nxt[i][j]=lst[j];
		}
		lst[s[i]-'a']=i;
	}
	
	vector<int> dp(n+1,inf);//从i起跳，跳到n+1要几步
	dp[n]=1;
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<k;j++) {
			if (nxt[i][j] == n+1) dp[i]=1;
			else dp[i]=min(dp[i],dp[nxt[i][j]]+1);
		}
	}
	
	int q;
	cin>>q;
	while (q--) {
		string s1;
		cin>>s1;
		int id=0;
		for(int i=0;i<s1.size();i++) {
			id=nxt[id][s1[i]-'a'];
			if (id == n+1) break;
		}
		if (id == n+1) cout<<"0\n";
		else {
			cout<<dp[id]<<"\n";
		}
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









