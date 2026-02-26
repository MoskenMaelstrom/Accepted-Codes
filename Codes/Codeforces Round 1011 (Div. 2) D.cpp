// Problem: D. Serval and Kaitenzushi Buffet
// Contest: Codeforces - Codeforces Round 1011 (Div. 2)
// URL: https://codeforces.com/contest/2085/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	priority_queue<int> pq;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
		
	int ans=0;
	for(int i=0;i<n;i++) {
		pq.push(a[i]);
		if ((n-i-1)%(k+1) == k) {ans+=pq.top();pq.pop();}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









