// Problem: E. The Robotic Rush
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	vector<int> b(m);
	for(int i=0;i<m;i++) cin>>b[i];
	ranges::sort(b);
	
	string s;
	cin>>s;
	vector<int> pre(k);
	for(int i=0;i<k;i++) {
		if (s[i] == 'L') pre[i]=-1;
		else pre[i]=1;
	}
	for(int i=1;i<k;i++) pre[i]+=pre[i-1];
	map<int,int> mp;
	for(int i=0;i<k;i++) {
		if (!mp.count(pre[i])) mp[pre[i]]=i;
	}
	
	vector<int> ans(k);
	for(int i=0;i<n;i++) {
		auto l=upper_bound(b.begin(),b.end(),a[i]);
		auto r=lower_bound(b.begin(),b.end(),a[i]);
		l--;
		int id=inf;
		if (l >= b.begin()) {
			int p=*l;
			int d=p-a[i];
			if (mp.count(d)) id=min(id,mp[d]);
		}
		if (r < b.end()) {
			int p=*r;
			int d=p-a[i];
			if (mp.count(d)) id=min(id,mp[d]);
		}
		if (id != inf) ans[id]++;
	}
	
	for(int i=1;i<k;i++) ans[i]+=ans[i-1];
	for(auto e1 : ans) cout<<n-e1<<" ";
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







