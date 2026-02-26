// Problem: 小红出千
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125954/G
// Memory Limit: 512 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	auto b=a;
	ranges::sort(a);
	a.erase(unique(a.begin(),a.end()),a.end());
	
	int m=a.size();
	int p=0;
	int l=a[p],r=a[p]+n-1;
	auto seg=[&](int L,int R) {
		return upper_bound(a.begin(),a.end(),R)-lower_bound(a.begin(),a.end(),L);
	};
	int ans=n-seg(l,r);
	int l0=l,r0=r;
	
	while (++p < m) {
		int l=a[p];
		int r=a[p]+n-1;
		int cnt=n-seg(l,r);
		if (cnt < ans) {
			ans=cnt;
			l0=l;
			r0=r;
		}
		if (r >= a[m-1]) break;
	}
	
	cout<<ans<<"\n";
	vector<bool> id(n);
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		if (l0 <= b[i] and b[i] <= r0 and mp.count(b[i]) == 0) {
			mp[b[i]]=1;
			id[i]=1;
		}
	}
	
	for(int i=0;i<n;i++) {
		if (id[i]) continue;
		while (mp.count(l0)) l0++;
		cout<<i+1<<" "<<l0++<<"\n";
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







