// Problem: C - Brackets Stack Query
// Contest: AtCoder - AtCoder Beginner Contest 428
// URL: https://atcoder.jp/contests/abc428/tasks/abc428_c
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
	int q;
	cin>>q;
	int cnt=0;
	multiset<int> st;
	vector<int> a(1);
	a[0]=0;
	st.insert(0);
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			char c;
			cin>>c;
			if (c == '(') cnt++;
			else cnt--;
			a.push_back(cnt);
			st.insert(cnt);
		}
		else {
			st.erase(st.find(cnt));
			a.pop_back();
			cnt=a[a.size()-1];
		}
		
		if (cnt == 0 and *st.begin() == 0) cout<<"Yes\n";
		else cout<<"No\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









