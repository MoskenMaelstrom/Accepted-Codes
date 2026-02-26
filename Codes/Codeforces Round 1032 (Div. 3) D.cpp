// Problem: D. 1709
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/D
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
    vector<array<int,2>> o;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (a[j] > a[j+1]) o.push_back({1,j+1}),swap(a[j],a[j+1]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (b[j] > b[j+1]) o.push_back({2,j+1}),swap(b[j],b[j+1]);
        }
    }
    
    
    for (int i=0;i<n;i++) {
        if (a[i] >= b[i]) o.push_back({3,i+1}), swap(a[i],b[i]);
    }
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (a[j] > a[j+1]) o.push_back({1,j+1}),swap(a[j],a[j+1]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (b[j] > b[j+1]) o.push_back({2,j+1}),swap(b[j],b[j+1]);
        }
    }
    
    cout<<o.size()<<endl;
    for (auto [e1,e2] : o) cout<<e1<<" "<<e2<<endl;
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









