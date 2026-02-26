// Problem: C. Breach of Faith
// Contest: Codeforces - Codeforces Round 1008 (Div. 2)
// URL: https://mirror.codeforces.com/contest/2078/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> b(2*n);
	for(auto &e1 : b) cin>>e1;
	ranges::sort(b);
	
	
	int sum1=0,sum2=0;
	for(int i=n-1;i<2*n;i++) {
		sum1+=b[i];
	}
	for(int i=0;i<n-1;i++) {
		sum2+=b[i];
	}
	
	cout<<b[2*n-1]<<" "<<sum1-sum2<<" ";
	for(int i=0;i<n;i++) {
		if (i != n-1) cout<<b[i+n-1]<<" "<<b[i]<<" ";
		else cout<<b[i+n-1];
	}
	cout<<"\n";
	
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









