// Problem: B. ezraft and Array
// Contest: Codeforces - Codeforces Round 1108 (Div. 2)
// URL: https://codeforces.com/contest/2246/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	if (n == 1) cout<<"1\n";
	else if (n == 2) cout<<"-1\n";
	else {
		int sum=6;
		cout<<"1 2 3 ";
		for(int i=4;i<=n;i++) {
			cout<<sum<<" ";
			sum+=sum;
		}
		cout<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







