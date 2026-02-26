// Problem: B. Quasi Binary
// Contest: Codeforces - Codeforces Round 300
// URL: https://codeforces.com/problemset/problem/538/B
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
	vector<int> a;
	while (n != 0) {
		a.push_back(n%10);
		n/=10;
	}
	
	n=a.size();
	int cnt=0;
	vector<int> ans;
	while (*ranges::max_element(a) != 0) {
		int num=0;
		int c=1;
		for(int i=0;i<n;i++) {
			if (a[i] > 0) a[i]--,num+=c;
			c*=10;
		}
		cnt++;
		ans.push_back(num);
	}
	
	cout<<cnt<<'\n';
	for(auto e1 : ans) cout<<e1<<" ";
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









