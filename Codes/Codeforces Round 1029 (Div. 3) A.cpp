// Problem: A. False Alarm
// Contest: Codeforces - Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/contest/2117/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	
    int l=0,r=n-1;
    for (;l<n;l++) 
		if (a[l] == 1) break;
    for (;r>=0;r--)
        if (a[r] == 1)
            break;
    if (r-l+1 > x) cout<<"NO\n";
    else cout<<"YES\n";
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









