// Problem: E. Product of Closures
// Contest: Codeforces - Educational Codeforces Round 192 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2242/problem/E
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

void solve()
{
	int l,r,n;
	cin>>l>>r>>n;
	auto calc=[&](int num) {
		int res=0;
		while (num) {
			res++;
			num>>=1;
		}
		return res;
	};
	
	auto print=[&](int x,int y) -> void {
		int len1=calc(x);
		int len2=calc(y);
		for(int i=0;i<n;i++) {
			cout<<(((x>>(len1-1-i%len1))&1)&((y>>(len2-1-i%len2))&1));
		}
		cout<<"\n";
	};
	
	// print(4,11);
	// print(4,1);
	int c1=calc(r);
	int c2=calc(l);
	if (c1 == c2) {
		int p=-1;
		for(int i=30;i>=0;i--) {
			if (((l>>i)&1) == ((r>>i)&1)) continue;
			else {p=i;break;}
		}
		assert(p != -1);
		int x=r>>p<<p;
		int y=(r>>(p+1)<<(p+1))+((1<<p)-1);
		print(x,y);
	}
	else {
		// cout<<(1<<(c1-1))<<" "<<max(l,1ll<<(c1-2))<<"\n";
		print(1<<(c1-1),max(l,1ll<<(c1-2)));
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







