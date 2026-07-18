// Problem: Precision Error?!
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133876/G
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
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
	cout<<n*2<<"\n";
	int cnt=0;
	double z=0;
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			cnt++;
			double x=i*0.010000001;
			double y=j*0.010000001;
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<" "<<z<<"\n";
			if (cnt == n) break;
		}
		if (cnt == n) break;
	}
	
	cnt=0;
	z=0.9999;
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			cnt++;
			double x=i*0.010000001;
			double y=j*0.010000001;
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<" "<<z<<"\n";
			if (cnt == n) break;
		}
		if (cnt == n) break;
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







