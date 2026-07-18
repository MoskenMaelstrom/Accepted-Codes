// Problem: C. 砝码
// Contest: Codeforces - 2025年北京市大学生程序设计竞赛暨“小米杯”全国邀请赛
// URL: https://codeforces.com/gym/105851/problem/C
// Memory Limit: 512 MB
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
	int n,m;
	cin>>n>>m;
	if (m <= 30 and (1ll<<m) <= n) {cout<<"-1\n";return;}
	
	auto check=[&](int x) -> bool {
		int a=1;
		int cnt=1;
		while ((a<<1) <= x) a<<=1,cnt++;
		int sum=(a<<1)-1;
		if (cnt == m) return 1;
		else {
			int res=(n-sum+(m-cnt-1))/(m-cnt);
			return res <= x;
		}
	};
	
	int lo=1,hi=n,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	assert(res != -1);
	cout<<res<<"\n";
	
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







