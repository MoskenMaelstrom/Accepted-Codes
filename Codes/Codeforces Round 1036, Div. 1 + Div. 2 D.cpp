// Problem: D. Make a Palindrome
// Contest: Codeforces - EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2124/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector b=a;
	ranges::sort(b);
	int num=b[k-1];
	vector<int> c;
	for(int i=0;i<n;i++) {
		if (a[i] <= num) c.push_back(a[i]);
	}
	
	// for(auto e1 : c) cout<<e1<<" ";
	// cout<<endl;
	
	bool ok=1;
	int cnt=0;
	int l=0,r=c.size()-1;
	while (l < r) {
		if (c[l] == c[r]) l++,r--;
		else {
			if (c[l] < num and c[r] < num) {ok=0;break;}
			else if (c[l] < num) r--,cnt++;
			else if (c[r] < num) l++,cnt++;
		}
	}
	if (c.size()-cnt < k-1) ok=0;
	
	if (ok) cout<<"YES\n";
	else cout<<"NO\n";
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









