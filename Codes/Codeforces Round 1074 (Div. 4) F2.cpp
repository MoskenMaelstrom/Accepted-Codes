// Problem: F. BattleCows
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/F
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
	int n,q;
	cin>>n>>q;
	n=1<<n;
	vector<int> tree(n<<1);
	for(int i=0;i<n;i++) cin>>tree[n+i];
	for(int i=n-1;i>0;i--) tree[i]=tree[2*i]^tree[2*i+1];
	while (q--) {
		int id,v;
		cin>>id>>v;
		int ans=0,cur=n+id-1;
		for(int i=1;i<n;i<<=1) {
			if ((cur%2 == 0 and tree[cur^1] > v) or (cur%2 and tree[cur^1] >= v)) ans+=i;
			v^=tree[cur^1];
			cur>>=1;
		}
		cout<<ans<<"\n";
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







