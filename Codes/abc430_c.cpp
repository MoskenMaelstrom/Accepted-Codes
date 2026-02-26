// Problem: C - Truck Driver
// Contest: AtCoder - AtCoder Beginner Contest 430
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,A,B;
	cin>>n>>A>>B;
	vector<char> vec(n+1);
	for(int i=1;i<=n;i++) cin>>vec[i];
	vector<int> c0(n+1),c1(n+1);
	for(int i=1;i<=n;i++) {
		c0[i]=c0[i-1];
		c1[i]=c1[i-1];
		if (vec[i] == 'a') c0[i]++;
		if (vec[i] == 'b') c1[i]++;
	}
	
	int ans=0;
	for(int l=1;l<=n;l++) {
		int fa=A+c0[l-1];
		int fb=B+c1[l-1];
		int p0=lower_bound(c0.begin()+1,c0.end(),fa)-c0.begin();
		int p1=lower_bound(c1.begin()+1,c1.end(),fb)-c1.begin();
		ans+=max(0ll,p1-p0);
	}
	cout<<ans;
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







