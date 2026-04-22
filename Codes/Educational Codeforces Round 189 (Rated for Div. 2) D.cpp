// Problem: D. Exceptional Segments
// Contest: Codeforces - Educational Codeforces Round 189 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2225/problem/D
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

const int p=998244353;
void solve()
{
	int n,x;
	cin>>n>>x;
	if (x&1) {
		int t1=(x+1)/4%p;
		int t2=(n-x)/4%p;
		int t3=(x+1+2)/4%p;
		int t4=(n-x+2)/4%p;
		// cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<"\n";
		cout<<(t3*t4%p+t1*(1+t2)%p)%p<<"\n";
	}
	else {
		int t1=x/4%p;
		int t2=(n-x+1)/4%p;
		int t3=(x+2)/4%p;
		int t4=(n-x+3)/4%p;
		cout<<(t3*t4%p+(t1+1)*t2%p)%p<<"\n";
	}
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







