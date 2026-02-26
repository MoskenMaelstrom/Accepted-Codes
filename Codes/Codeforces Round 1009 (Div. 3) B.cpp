// Problem: The Third Side
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2074/problem/B
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
	int sum=0;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		sum+=num;
	}
	cout<<sum-n+1<<endl;
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









