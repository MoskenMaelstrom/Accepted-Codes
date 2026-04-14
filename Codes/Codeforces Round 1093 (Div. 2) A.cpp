// Problem: A. Blocked
// Contest: Codeforces - Codeforces Round 1093 (Div. 2)
// URL: https://codeforces.com/contest/2220/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	vector<int> a(105);
	for(int i=0;i<n;i++) {
		cin>>vec[i];
		a[vec[i]]++;
	}
	bool ok=1;
	for(int i=0;i<105;i++) {
		if (a[i] >= 2) ok=0;
	}
	if (!ok) {cout<<"-1\n";return;}
	ranges::sort(vec,greater<int>());
	for(auto e1 : vec) cout<<e1<<" ";
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







