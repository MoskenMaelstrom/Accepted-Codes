// Problem: x?y?n!
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/F
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	cout<<(n<<31)+n<<" "<<(n<<31)<<"\n";
	// cout<<(((n<<31)+n)^(n<<31))<<"\n";
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







