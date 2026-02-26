// Problem: D - Forbidden List 2
// Contest: AtCoder - AtCoder Beginner Contest 440
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_d
// Memory Limit: 1024 MB
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	
	auto check=[&](int num,int x,int y) -> bool {
		int p1=ranges::lower_bound(a,x)-a.begin();
		int p2=ranges::lower_bound(a,num)-a.begin();
		if (num-x+1-(p2-p1) <= y) return 1;
		else return 0;
	};
	
	while (q--) {
		int x,y;
		cin>>x>>y;
		int lo=x+y-1,hi=3e9,res=-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			if (check(mid,x,y)) res=mid,lo=mid+1;
			else hi=mid-1;
		}
		cout<<res<<"\n";
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







