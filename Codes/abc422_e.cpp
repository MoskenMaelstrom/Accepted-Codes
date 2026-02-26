// Problem: E - Colinear
// Contest: AtCoder - AtCoder Beginner Contest 422
// URL: https://atcoder.jp/contests/abc422/tasks/abc422_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

int randINT(int l, int r) {
    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	for(int t=0;t<100;t++) {
		auto [x1,y1]=a[randINT(0,n-1)];
		auto [x2,y2]=a[randINT(0,n-1)];
		if (x1 == x2 and y1 == y2) continue;
		int A=y2-y1;
		int B=x1-x2;
		int C=-x1*y2+x2*y1;
		int cnt=0;
		for(int i=0;i<n;i++) {
			auto [x,y]=a[i];
			if (A*x+B*y+C == 0) cnt++;
		}
		if (cnt > n/2) {
			cout<<"Yes\n";
			cout<<A<<" "<<B<<" "<<C;
			return;
		}
	}
	cout<<"No";
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









