// Problem: D. Largest Digit
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	auto calc=[&](int x) {
		int res=0;
		while (x) {
			res=max(res,x%10);
			x/=10;
		}
		return res;
	};
	
	int ans=0;
	for(int i=l1;i<=min(l1+30,r1);i++) {
		for(int j=l2;j<=min(l2+30,r2);j++) {
			ans=max(ans,calc(i+j));
		}
	}
	cout<<ans<<"\n";
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







