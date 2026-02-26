// Problem: 智乃的算法竞赛群友
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/F
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
	int n,a,b;
	cin>>n>>a>>b;
	int c=a+b;
	int ans1=n/2*b;
	int ans2=n/8*c+n%8/2*b;
	int ans3=0;
	for(int i=0;i<=10;i++) {
		if (n >= i*7) {
			int rest=n-i*7;
			ans3=max(ans3,rest/8*c+i*a);
		}
	}
	int ans4=0;
	for(int i=0;i<=10;i++) {
		if (n >= i*8) {
			int rest=n-i*8;
			ans4=max(ans4,rest/7*a+i*c);
		}
	}
	cout<<max({ans1,ans2,ans3,ans4})<<"\n";
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







