// Problem: C1. The Cunning Seller (easy version)
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/C1
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

int cost(int x) {
    if (x == 0) return 3;
    int p=1;
    for (int i=0;i<=x;i++) p*=3;
    return p+x*(p/9);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> d;
	
	int temp=n;
	while (temp > 0) {
		d.push_back(temp%3);
		temp/=3;
	}
	
	int ans=0;
	for(int i=0;i<d.size();i++) {
		if (d[i] != 0) {
			ans+=cost(i)*d[i];
		}
	}
	cout<<ans<<'\n';
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









