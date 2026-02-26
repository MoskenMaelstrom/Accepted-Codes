// Problem: D - Least Unbalanced
// Contest: AtCoder - AtCoder Beginner Contest 422
// URL: https://atcoder.jp/contests/abc422/tasks/abc422_d
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

void solve()
{
	int n,k;
	cin>>n>>k;
	int ans=0;
	vector<int> a(1<<n);
	auto work=[&](auto self,int l,int r,int sum) -> void {
		if (l == r) {a[l]=sum;return;}
		int m=l+r>>1;
		if (sum%2 == 0) {
			self(self,l,m,sum/2);
			self(self,m+1,r,sum/2);
		}
		else {
			self(self,l,m,sum/2);
			self(self,m+1,r,sum/2+1);
			ans=1;
		}
	};
	work(work,0,(1<<n)-1,k);
	cout<<ans<<"\n";
	for(auto e1 : a) cout<<e1<<" ";
	cout<<"\n";
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









