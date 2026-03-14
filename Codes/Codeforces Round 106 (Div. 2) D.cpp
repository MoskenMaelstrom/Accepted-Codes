// Problem: D. Coloring Brackets
// Contest: Codeforces - Codeforces Round 106 (Div. 2)
// URL: https://codeforces.com/problemset/problem/149/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=700;
const int p=1e9+7;
int dp[N+1][N+1][3][3];
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	vector<int> R(n);
	vector<int> sta;
	for(int i=0;i<n;i++) {
		if (s[i] == '(') sta.push_back(i);
		else R[sta.back()]=i,sta.pop_back();
	}
	
	function<int(int,int,int,int)> dfs=[&](int l,int r,int cl,int cr) -> int {
		if (l > r) return 1;
		if (dp[l][r][cl][cr]) return dp[l][r][cl][cr];
		
		int res=0;
		for(int c=1;c<=2;c++) {
			if (R[l] < r or c != cr) (res+=dfs(l+1,R[l]-1,0,c)*dfs(R[l]+1,r,c,cr)%p)%=p;
			if (c != cl) (res+=dfs(l+1,R[l]-1,c,0)*dfs(R[l]+1,r,0,cr)%p)%=p;
		}
		return dp[l][r][cl][cr]=res;
	};
	cout<<dfs(0,n-1,0,0);
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







