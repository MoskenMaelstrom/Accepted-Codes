// Problem: H. Loose Subsequences
// Contest: Codeforces - The 2025 Jiangsu Collegiate Programming Contest, The 2025 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105945/problem/H
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> dp(n+1);
	vector<int> pre(n+1);
	s=" "+s;
	
	vector<int> lst(26);
	for(int i=1;i<=n;i++) {
		if (lst[s[i]-'a'] == 0) {
			dp[i]=pre[max(0ll,i-k-1)]+1;	
			dp[i]%=p;
		}
		else {
			dp[i]=pre[max(0ll,i-k-1)]-pre[max(0ll,lst[s[i]-'a']-k-1)];
			dp[i]%=p;
		}
		pre[i]=pre[i-1]+dp[i];
		pre[i]%=p;
		lst[s[i]-'a']=i;
	}
	cout<<(pre[n]+p)%p<<"\n";
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







