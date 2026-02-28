// Problem: F. Mooclear Reactor 2
// Contest: Codeforces - Codeforces Round 1084 (Div. 3)
// URL: https://codeforces.com/contest/2200/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	vector<array<int,2>> b(m);
	for(int i=0;i<m;i++) cin>>b[i][0]>>b[i][1];
	
	vector vec(n+1,vector<int>(0));
	for(int i=0;i<n;i++) {
		vec[min(a[i][1],n)].push_back(a[i][0]);
	}
	
	int res=0;
	vector<int> val(n+2,-inf);
	priority_queue<int,vector<int>,greater<int>> pq;
	int cur=0;
	for(int k=n+1;k>=1;k--) {
		while (pq.size() > k) {
			cur-=pq.top();
			pq.pop();
		}
	
		if (k-1 <= n) {
			for(auto x : vec[k-1]) {
				pq.push(x);
				cur+=x;
				while (pq.size() > k) {
					cur-=pq.top();
					pq.pop();
				}
			}
		}
		
		if (pq.size() == k) res=max(res,cur),val[k]=cur-pq.top();
		else if (pq.size() == k-1) val[k]=cur;
	}
	vector<int> pre(n+2,-inf);
	for(int k=1;k<=n+1;k++) {
		pre[k]=max(pre[k-1],val[k]);
	}
	
	for(int i=0;i<m;i++) {
		auto [x,y]=b[i];
		y=min(n,y);
		cout<<max(res,x+pre[y+1])<<" ";
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







