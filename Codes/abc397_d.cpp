// Problem: D - Cubes
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int N=1e18;
const int Y_up=6e8;
void solve()
{
	int n;
	cin>>n;
	for(int d=1;d<=1000000;d++) {
		if (n%d != 0) continue;
		int l=0,r=Y_up,ans=-1;
		while (l <= r) {
			int mid=l+r>>1;
			if (3*mid*mid+3*d*mid+d*d-n/d >= 0) ans=mid,r=mid-1;
			else l=mid+1;
		}
		if (3*ans*ans+3*d*ans+d*d-n/d == 0 and ans > 0) {cout<<d+ans<<" "<<ans;return;}
	}
	cout<<-1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









