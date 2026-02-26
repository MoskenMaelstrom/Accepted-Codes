// Problem: D. Retaliation
// Contest: Codeforces - Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/contest/2117/problem/D
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
    bool ok=1;
    int d=a[1]-a[0];
    int d1=(a[0]-d)/(n+1);
    int p=d+d1;
    if (p < 0 or d1 < 0) cout<<"NO\n";
    else {
	    for (int i=0;i<n;i++) {
	        if (a[i] != d1*(n+1)+d*(i+1))
	            ok=0;
	    }
	    if (ok) cout<<"YES\n";
	    else cout<<"NO\n";
    }
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









