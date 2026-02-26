// Problem: A. All Lengths Subtraction
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/contest/2143/problem/A
// Memory Limit: 256 MB
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
	int flag=1;
    int n,l,r;
    cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        if (a[i] == n) l=i,r=i;
    }
    int pos=n;
    while (pos != 0) {
        if (a[l] != pos and a[r] != pos) {flag=0;break;}
        if (l >= 1 and a[l] == pos) l--;
        if (r <= n and a[r] == pos) r++;
        pos--;
    }
    if (pos == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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









