// Problem: C1. Skibidus and Fanum Tax (easy version)
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+1;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for(auto &ele : a) cin>>ele;
    for(auto &ele : b) cin>>ele;
    ranges::sort(b);
    
    int lst = -inf;
    for (int i = 0; i < n; i++) {
        int x = inf;
        if (a[i] >= lst) x = a[i];
        auto it = lower_bound(b.begin(), b.end(), lst + a[i]);
        if (it != b.end()) {
            x = min(x, *it - a[i]);
        }
        if (x == inf) {cout << "NO\n";return;}
        lst = x;
    }
    cout << "YES\n";
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









