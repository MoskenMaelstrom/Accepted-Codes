// Problem: E. New Year's Gifts
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/E
// Memory Limit: 512 MB
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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(m);
	for(int i=0;i<m;i++) cin>>a[i];
	vector<array<int,2>> vec(n);
	for(int i=0;i<n;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		vec[i][0]=x;
		vec[i][1]=z-y;
		k-=y;
	}
	
	ranges::sort(a);
	ranges::sort(vec);
	
	priority_queue<int> pq;
	int id=0;
	int cnt=0;
	for(int i=0;i<m;i++) {
		while (id < n and vec[id][0] <= a[i]) {
			pq.push(vec[id][1]);
			id++;
		}
		
		if (!pq.empty()) {
			pq.pop();
			cnt++;
		}
	}
	
	vector<int> b;
	while (!pq.empty()) {
		b.push_back(pq.top());
		pq.pop();
	}
	
	for(int i=id;i<n;i++) b.push_back(vec[i][1]);
	ranges::sort(b);
	for(auto c : b) {
		if (k >= c) {
			k-=c;
			cnt++;
		}
		else break;
	}
	
	cout<<cnt<<"\n";
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







