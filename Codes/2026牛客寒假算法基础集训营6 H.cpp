// Problem: 小L的数组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/H
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	set<int> st;
	st.insert(0);
	for(int i=1;i<=n;i++) {
		set<int> cur;
		for(auto e1 : st) {
			cur.insert(max(0ll,e1-a[i]));
			cur.insert(e1^b[i]);
		}
		st=cur;
	}
	cout<<*st.rbegin();
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







