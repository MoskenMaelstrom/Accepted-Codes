// Problem: D. Tree Jumps
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/D
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
	int n;
	cin>>n;
	vector<int> f(n+1);//1~n个点
	for(int i=2;i<=n;i++) {
		int fa;
		cin>>fa;
		f[i]=fa;
	}
	
	vector<int> dep(n+1);
	dep[1]=0;
	for(int i=2;i<=n;i++) {
		dep[i]=dep[f[i]]+1;
	}
	
	vector vec(n+1,vector<int>(0));
	for(int i=1;i<=n;i++) {
		vec[dep[i]].push_back(i);
	}
	
	// for(int i=0;i<=n;i++) {
		// for(auto ele : vec[i]) cout<<ele<<" ";
		// cout<<endl;
	// }
	
	vector<int> dp(n+1,0);
	dp[1]=1;
	int psum=1;
	for(int i=1;i<=n;i++) {
		int sum=0;
		for(auto ele : vec[i]) {
			dp[ele]=psum;
			if (i != 1) dp[ele]=(dp[ele]-dp[f[ele]]+p)%p;
			sum=(sum+dp[ele])%p;
		}
		psum=sum;
	}
	
	int ans=0;
	for(auto ele : dp) ans=(ans+ele)%p;
	cout<<ans<<endl;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









