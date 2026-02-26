// Problem: B. Incremental Path
// Contest: Codeforces - Codeforces Round 1053 (Div. 2)
// URL: https://codeforces.com/contest/2151/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n,m;
	cin>>n>>m;
	int N=n+m+10;
	N<<=1;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> a(m+1);
	for(int i=1;i<=m;i++) {
		cin>>a[i];
	}
	
	set<int> st;
	for(int i=1;i<N;i++) st.insert(i);
	for(int i=1;i<=m;i++) {
		st.erase(a[i]);
	}
	
	int pre=1;
	if (s[1] == 'A') pre++;
	else pre=*st.upper_bound(pre);
	st.erase(pre);
	a.push_back(pre);
	for(int i=2;i<=n;i++) {
		if (s[i-1] == 'B') pre=*st.upper_bound(pre);
		if (s[i] == 'A') pre++;
		else {
			pre=*st.upper_bound(pre);
		}
		st.erase(pre);
		a.push_back(pre);
	}
	
	ranges::sort(a);
	st.clear();
	for(int i=1;i<a.size();i++) st.insert(a[i]);
	
	cout<<st.size()<<"\n";
	for(auto e1 : st) cout<<e1<<" ";
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









