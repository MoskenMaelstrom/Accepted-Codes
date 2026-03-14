// Problem: P4999 烦人的数学作业
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4999
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int p=1e9+7;

int work(int x) {
	if (x == 0) return 0;
	vector<int> a;
	vector dp(20,vector<int>(200,-1));
	while (x) {
		a.push_back(x%10);
		x/=10;
	}
	
	function<int(int,int,int)> dfs=[&](int pos,int sum,bool limit) {
		if (pos == -1) return sum;
		if (limit == 0 and dp[pos][sum] != -1) return dp[pos][sum];
		
		int res=0;
		int up=limit ? a[pos] : 9;
		for(int i=0;i<=up;i++) {
			(res+=dfs(pos-1,sum+i,limit and (i == up)))%=p;
		}
		if (limit == 0) dp[pos][sum]=res;
		return res;
	};
	return dfs(a.size()-1,0,1);
}

void solve()
{
	int l,r;
	cin>>l>>r;
	cout<<((work(r)-work(l-1))%p+p)%p<<"\n";
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







