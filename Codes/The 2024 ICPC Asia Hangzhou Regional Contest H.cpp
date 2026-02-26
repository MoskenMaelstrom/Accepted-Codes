// Problem: H. Heavy-light Decomposition
// Contest: Codeforces - The 2024 ICPC Asia Hangzhou Regional Contest (The 3rd Universal Cup. Stage 25: Hangzhou)
// URL: https://codeforces.com/gym/105657/problem/H
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<array<int,3>> a(k);
	for(int i=0;i<k;i++) {
		int l,r;
		cin>>l>>r;
		int len=r-l;
		a[i]={len,l,r};
	}
	ranges::sort(a);
	
	vector<int> fa(n+1);
	auto work=[&](int id,int p) -> void {
		auto [len,l,r]=a[id];
		fa[l]=p;
		for(int i=l+1;i<=r;i++) {
			fa[i]=i-1;
		}
	};
		
	if (k != 1 and a[k-1][0] == a[k-2][0] and a[k-1][0]-a[0][0] <= 1) cout<<"IMPOSSIBLE\n";
	else {
		auto [len,l,r]=a[k-1];
		work(k-1,0);
		
		if (k != 1) {	
			if (a[k-1][0] == a[k-2][0]) {
				work(0,l+1);	
				for(int i=1;i<k-1;i++) work(i,l);
			}
			else {
				for(int i=0;i<k-1;i++) work(i,l);
			}
		}
		for(int i=1;i<=n;i++) cout<<fa[i]<<" ";
		cout<<"\n";
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







