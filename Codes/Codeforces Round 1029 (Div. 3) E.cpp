// Problem: E. Lost Soul
// Contest: Codeforces - Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/contest/2117/problem/E
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
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	
	set<int> st;
	int ansi=-1;
	for(int i=n-1;i>=0;i--) {
		if (a[i] == b[i]) {ansi=max(ansi,i);break;}
	}
	
	for(int i=n-1;i>=0;i--) {
		if (st.contains(a[i])) {ansi=max(ansi,i);break;}
		st.insert(a[i]);
	}
	
	st.clear();
	for(int i=n-1;i>=0;i--) {
		if (st.contains(b[i])) {ansi=max(ansi,i);break;}
		st.insert(b[i]);
	}
	
	st.clear();
	st.insert(a[n-1]);
	for(int i=n-3;i>=0;i--) {
		if (st.contains(b[i])) {ansi=max(ansi,i);break;}
		st.insert(a[i+1]);
	}
	
	st.clear();
	st.insert(b[n-1]);
	for(int i=n-3;i>=0;i--) {
		if (st.contains(a[i])) {ansi=max(ansi,i);break;}
		st.insert(b[i+1]);
	}
	
	cout<<ansi+1<<"\n";
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









