// Problem: 一念神魔之耀
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/L
// Memory Limit: 512 MB
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

void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	if (y > x) swap(x,y);
	vector<int> a(n+1,1);
	for(int i=1;i<=n;i++) {
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	vector b=a;
	int g=gcd(x,y);
	for(int i=1;i<=n-g+1;i++) {
		if (a[i] == 0) {
			for(int j=i;j<i+g;j++) {
				a[j]^=1;
			}
		}
	}
	if (*ranges::min_element(a) == 0) {
		cout<<"-1\n";
		return;
	}
	
	vector<array<int,2>> ans;
	auto work=[&](int l,int r) {
		for(int i=l;i<=r;i++) {
			b[i]^=1;
		}
		ans.push_back({l,r});
	};
	for(int i=1;i<=n;i++) {
		if (b[i] == 1) continue;
		if (i <= x) {
			if (b[i] == 1) continue;
			int ed=i+g-1;
			int p=i+x-1;
			work(i,i+x-1);
			while (p != ed) {
				while (p-y < ed and p+x <= n) {
					work(p+1,p+x);
					p+=x;
				}
				work(p-y+1,p);
				p-=y;
			}
		}
		else {
			if (b[i] == 1) continue;
			int st=i+g-1;
			int p=st-x+1;
			work(p,p+x-1);
			while (p != i) {
				while (p+y > st and p-x >= 1) {
					work(p-x,p-1);
					p-=x;
				}
				work(p,p+y-1);
				p+=y;
			}
		}
	}
	
	cout<<ans.size()<<'\n';
	for(auto [e1,e2] : ans) {
		cout<<e1<<' '<<e2<<'\n';
	}
	// for(auto e1 : b) cout<<e1<<" ";
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






