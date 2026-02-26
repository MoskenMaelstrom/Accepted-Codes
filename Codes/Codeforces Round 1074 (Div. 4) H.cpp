// Problem: H. BattleCows 2
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/H
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	vector<array<int,2>> vec;
	for(int i=1;i<=n;i++) {
		if (a[i] > pre[i-1]) vec.push_back({i,a[i]-pre[i-1]});
	}
	ranges::reverse(vec);
	
	auto calc=[&](int l,int r,int cur,int step) -> int {
		if (step < 0) return 0;
		for(auto [id,d] : vec) {
			if (id > cur or a[cur] < d) {
				step--;
				if (step < 0) {l=max(l,id+(id < cur));break;}
			}
		}
		return max(r-l+1,0ll);
	};
	
	for(int i=1;i<=n;i++) {
		int x;
		if (a[i] > pre[i-1]) x=lower_bound(pre.begin()+1,pre.end(),2*a[i])-pre.begin();
		else x=lower_bound(pre.begin()+1,pre.end(),a[i])-pre.begin()+1;
		cout<<calc(1,x-1,i,k)+calc(x,n,i,k-1)<<" ";
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







