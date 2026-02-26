// Problem: D. Eating
// Contest: Codeforces - Codeforces Round 1005 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2064/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<array<int,32>> left(n+1);//向左最多到哪里
	vector<int> pre(n+1);
	left[0].fill(1);
	for(int i=1;i<=n;i++) pre[i]=(a[i]^pre[i-1]);	
	
	for(int i=1;i<=n;i++) {
		left[i]=left[i-1];
		int d=__lg(a[i])+1;
		for(int j=0;j<=d;j++) {
			left[i][j]=i;
		}
	}
	
	auto f=[&](int p1,int p2) {
		if (p1 > p2) return 0ll;
		return pre[p1-1]^pre[p2];
	};
	
	while (q--) {
		int x;
		cin>>x;
		int p=n,ans=0;
		while (p >= 1) {
			int d=__lg(x)+1;
			int p1=left[p][d];
			// cout<<"p1:"<<p1<<endl;
			if ((x^f(p1+1,p)) < a[p1]) {
				x=(x^f(p1+1,p));
				ans+=p-p1;
				p=p1;
				break;
			}
			else {
				x=(x^f(p1,p));
				ans+=p-p1+1;
				p=p1-1;
			}
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
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









