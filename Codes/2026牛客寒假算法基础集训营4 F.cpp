// Problem: 爱音的01串构造
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/F
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
	int a,b;
	cin>>a>>b;
	if (a >= b) {
		int len=a/(b+1);
		int rest=a%(b+1);
		for(int i=0;i<=b;i++) {
			int cur=len+(i < rest ? 1 : 0);
			for(int k=0;k<cur;k++) cout<<0;
			if (i < b) cout<<1;
		}
	}
	else {
		int len=b/(a+1);
		int rest=b%(a+1);
		for(int i=0;i<=a;i++) {
			int cur=len+(i < rest ? 1 : 0);
			for(int k=0;k<cur;k++) cout<<1;
			if (i < a) cout<<0;
		}
	}
	cout<<"\n";
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







