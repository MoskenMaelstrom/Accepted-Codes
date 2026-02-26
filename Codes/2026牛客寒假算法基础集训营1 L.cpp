// Problem: Need Zero
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/L
// Memory Limit: 512 MB
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
	int x=n%10;
	if (x == 0) cout<<"1";
	else if (x == 5) cout<<"2";
	else if (x == 2) cout<<"5";
	else if (x == 4) cout<<"5";
	else if (x == 6) cout<<"5";
	else if (x == 8) cout<<"5";
	else cout<<"10";
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







