// Problem: A. Printer
// Contest: Codeforces - The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105385/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<array<int,3>> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	auto check=[&](int x) {
		int cnt=0;
		for(auto [t,l,w] : a) {
			cnt+=l*(x/(t*l+w))+min(l,x%(t*l+w)/t);
			if (cnt >= k) return 1;
		}
		return 0;
	};

	int lo=1,hi=3e18,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) hi=mid-1,res=mid;
		else lo=mid+1;
	}
	cout<<res<<"\n";
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







