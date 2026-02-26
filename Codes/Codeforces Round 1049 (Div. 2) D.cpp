// Problem: D. A Cruel Segment's Thesis
// Contest: Codeforces - Codeforces Round 1049 (Div. 2)
// URL: https://codeforces.com/contest/2140/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,3>> a;
	int ans=0;
	for(int i=0;i<n;i++) {
		int l,r;
		cin>>l>>r;
		ans+=r-l;
		a.push_back({l+r,l,r});
	}
	ranges::sort(a);
	
	for(int i=0;i<a.size()/2;i++) {
		ans+=a[n-i-1][2]-a[i][1];
	}
	if (a.size()%2 == 0) {
		cout<<ans<<"\n";
	}
	else {
		int res=ans;
		int mid=a.size()>>1;
		for(int i=0;i<mid;i++) {
			int t=ans;
			t+=a[i][1];
			t-=a[mid][1];
			res=max(res,t);
		}
		for(int i=mid+1;i<n;i++) {
			int t=ans;
			t-=a[i][2];
			t+=a[mid][2];
			res=max(res,t);
		}
		cout<<res<<"\n";
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







