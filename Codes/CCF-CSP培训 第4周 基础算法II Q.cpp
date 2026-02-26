// Problem: Q - Find Permutation 2
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/Q
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	set<int> st;
	vector<int> b(n);
	for(int i=0;i<n;i++) {
		if (a[i] == -1) continue;
		if (st.find(a[i]) != st.end()) {
			cout<<"No";
			return;
		}
		
		st.insert(a[i]);
		b[i]=a[i];
	}
	
	for(int i=0;i<n;i++) {
		if (a[i] == -1) {
			for(int j=1;j<=n;j++) {
				if (st.find(j) == st.end()) {
					b[i]=j;
					st.insert(j);
					break;
				}
			}
		}
	}
	cout<<"Yes\n";
	for(auto e1 : b) cout<<e1<<" ";
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









