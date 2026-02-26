// Problem: 智乃的瓷砖
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/B
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
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (((i+j)&1)) cout<<"\\";
			else cout<<"/";
		}
		cout<<"\n";
	}
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







