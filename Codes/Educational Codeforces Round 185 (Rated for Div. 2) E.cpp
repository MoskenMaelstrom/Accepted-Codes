// Problem: E. Binary Strings and Blocks
// Contest: Codeforces - Educational Codeforces Round 185 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2170/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=998244353;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> l(n+1);
	for(int i=0;i<m;i++) {
		int L,R;
		cin>>L>>R;
		l[R]=max(l[R],L);
	}
	for(int i=1;i<=n;i++) l[i]=max(l[i],l[i-1]);
	
	vector<int> dp(n+1);
	vector<int> pre(n+1);
	dp[0]=pre[0]=2;
	for(int i=1;i<=n;i++) {
		int val=pre[i-1];
		if (l[i] != 0) val-=pre[l[i]-1];
		dp[i]=val;
		pre[i]=pre[i-1]+dp[i];
		dp[i]%=p;
		pre[i]%=p;
	}
	cout<<(dp[n]+p)%p<<"\n";
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







