// Problem: B. Cyclists
// Contest: Codeforces - Codeforces Round 1086 (Div. 2)
// URL: https://codeforces.com/contest/2208/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,k,p,m;
	cin>>n>>k>>p>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	priority_queue<int,vector<int>,greater<int>> pq;
	
	int cost=0;
	if (k == n) cout<<m/a[p]<<"\n";
	else if (p <= k) {
		cost+=a[p];
		if (cost > m) {cout<<"0\n";return;}
		for(int i=1;i<=k+1;i++) {
			if (i == p) continue;
			pq.push(a[i]);
		}
		
		int cnt=0;
		for(int i=k+2;i<a.size();i++) {
			cost+=pq.top();
			cnt+=pq.top();
			pq.pop();
			pq.push(a[i]);
		}
		cost+=pq.top();cnt+=pq.top();
		cost+=a[p];cnt+=a[p];
		m-=cost;
		if (m < 0) {cout<<"1\n";return;}
		cout<<m/cnt+2<<"\n";
	}
	else {
		for(int i=1;i<=k;i++) pq.push(a[i]);
		int id=k+1;
		while (id < p) {
			cost+=pq.top();
			a.push_back(pq.top());
			pq.pop();
			pq.push(a[id++]);
		}
		cost+=pq.top();
		a.push_back(pq.top());
		pq.pop();
		cost+=a[p];
		pq.push(a[++id]);
		if (cost > m) {cout<<"0\n";return;}
		
		int cnt=0;
		for(int i=p+2;i<a.size();i++) {
			cost+=pq.top();
			cnt+=pq.top();
			pq.pop();
			pq.push(a[i]);
		}
		cost+=pq.top();cnt+=pq.top();
		cost+=a[p];cnt+=a[p];
		m-=cost;
		if (m < 0) {cout<<"1\n";return;}
		cout<<m/cnt+2<<"\n";
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







