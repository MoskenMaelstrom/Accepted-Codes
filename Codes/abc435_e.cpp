// Problem: E - Cover query
// Contest: AtCoder - AtCoder Beginner Contest 435
// URL: https://atcoder.jp/contests/abc435/tasks/abc435_e
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
	map<int,int> seg;
	int ans=n;
	while (q--) {
		int l,r;
		cin>>l>>r;
		
		int nl=l,nr=r;
		auto it=seg.lower_bound(l);
		if (it != seg.begin()) {
			it--;
			if (it->second >= l) {
				nl=it->first;
				nr=max(nr,it->second);
				ans+=it->second-it->first+1;
				it=seg.erase(it);
			}
			else it++;
		}
		while (it != seg.end() and it->first <= r) {
			nr=max(it->second,nr);
			ans+=it->second-it->first+1;
			it=seg.erase(it);
		}
		seg[nl]=nr;
		ans-=nr-nl+1;
		cout<<ans<<"\n";
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







