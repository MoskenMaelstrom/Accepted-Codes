// Problem: J. New Energy Vehicle
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Harbin Onsite (The 3rd Universal Cup. Stage 14: Harbin)
// URL: https://codeforces.com/gym/105459/problem/J
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

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(n),x(m+1),t(m+1);
    vector nxt(n,vector<int>(0));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) {
		cin>>x[i]>>t[i];
		t[i]--;
		nxt[t[i]].push_back(x[i]);
	}
	x[m]=inf;
	t[m]=-1;
	for(int i=0;i<n;i++) {
		b[i]=a[i];
		nxt[i].push_back(inf);
		ranges::reverse(nxt[i]);
		pq.push({nxt[i].back(),i});
	}
	int cur=0;
	for(int i=0;i<=m;i++) {
		while (cur < x[i] and pq.size()) {
			int id=pq.top().second;
			int t0=min(b[id],x[i]-cur);
			b[id]-=t0;
			cur+=t0;
			if (!b[id] or t[i] == id) pq.pop();
		}
		if (cur < x[i]) {
			cout<<cur<<"\n";
			return;
		}
		nxt[t[i]].pop_back();
		b[t[i]]=a[t[i]];
		pq.push({nxt[t[i]].back(),t[i]});
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








