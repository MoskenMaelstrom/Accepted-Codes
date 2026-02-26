// Problem: D2. Red Light, Green Light (Hard version)
// Contest: Codeforces - Codeforces Round 1030 (Div. 2)
// URL: https://codeforces.com/contest/2118/problem/D2
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
	
	vector<int> p(n),d(n);
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++) cin>>d[i];
	vector<int> nxt(2*n,-1);
	map<int,int> f;
	for(int i=n-1;i>=0;i--) {
		int v=((d[i]-p[i])%k+k)%k;
		if (f.contains(v)) {
			nxt[i+n]=f[v];
		}
		f[v]=i;
	}
	f.clear();
	for(int i=0;i<n;i++) {
		int v=((d[i]+p[i])%k+k)%k;
		if (f.contains(v)) {
			nxt[i]=n+f[v];
		}
		f[v]=i;
	}
	
	
	vector adj(2*n,vector<int>(0));
	queue<int> q;
	vector<bool> out(2*n);
	for(int i=0;i<2*n;i++) {
		if (nxt[i] == -1) {
			out[i]=1;
			q.push(i);
		}
		else adj[nxt[i]].push_back(i);
	}
	
	while (!q.empty()) {
		int x=q.front();
		q.pop();
		for(auto y : adj[x]) {
			out[y]=1;
			q.push(y);
		}
	}
	
	map<int,vector<array<int,2>>> vec;
	for(int i=0;i<n;i++) {
		int v=(p[i]-d[i]+k)%k;
		vec[v].push_back({p[i],i});
	}
	
	int Q;
	cin>>Q;
	while (Q--) {
		int a;
		cin>>a;
		if (!vec.contains(a%k)) {
			cout<<"YES\n";
			continue;
		}
		
		auto &v=vec[a%k];
		auto it=lower_bound(v.begin(),v.end(),array<int,2>{a,0ll});
		if (it == v.end()) {
			cout<<"YES\n";
			continue;
		}
		auto i=*it;
		if (out[i[1]]) cout<<"YES\n";
		else cout<<"NO\n";
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






