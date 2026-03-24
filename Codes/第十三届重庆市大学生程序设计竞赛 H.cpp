// Problem: H. 连接
// Contest: Codeforces - 第十三届重庆市大学生程序设计竞赛
// URL: https://codeforces.com/gym/105887/problem/H
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
	int n;
	cin>>n;
	vector<int> vec(n);
	vector<int> p(n);
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		x--;
		p[x]=i;
	}
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		x--;
		vec[i]=p[x];
	}
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];
	
	set<int> st;
	for(int i=0;i<n;i++) {
		if (c[i]) st.insert(i);
	}
	for(int i=n-1;i>=0;i--) {
		if (c[vec[i]] == 0) continue;
		if (st.upper_bound(vec[i]) != st.end()) {cout<<"No\n";return;}
		st.extract(vec[i]);
	}
	cout<<"Yes\n";
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







