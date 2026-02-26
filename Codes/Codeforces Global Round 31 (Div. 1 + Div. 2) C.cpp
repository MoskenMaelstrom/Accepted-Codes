// Problem: C. XOR-factorization
// Contest: Codeforces - Codeforces Global Round 31 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2180/problem/C
// Memory Limit: 256 MB
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
	int n,k;
	cin>>n>>k;
	
	if (k%2 == 1) {
		for(int i=0;i<k;i++) cout<<n<<" ";
		cout<<"\n";
		return;
	}
	
	vector<int> ans(k);
	int p=0;
	for(int b=32;b>=0;b--) {
		if ((n>>b)&1) {
			p=min(p+1,k);
			for(int i=0;i<p-1;i++) ans[i]+=1ll<<b;
			for(int i=p;i<k;i++) ans[i]+=1ll<<b;
		}
		else {
			if (p%2 == 0) {
				for(int i=0;i<p;i++) ans[i]+=1ll<<b;
			}
			else {
				for(int i=0;i<p-1;i++) ans[i]+=1ll<<b;
			}
		}
	}
	
	for(auto e1 : ans) cout<<e1<<" ";
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







