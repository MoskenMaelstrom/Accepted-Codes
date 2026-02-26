// Problem: Jetton
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/J
// Memory Limit: 1024 MB
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
	int x,y;
	cin>>x>>y;
	int g=gcd(x,y);
	// x/=g;y/=g;
	set<int> st;
    int num=(x+y)/g;
    for (int i=32;i>=0; i--) {
        if (num == (1ll << i)) {
            cout<<i<<'\n';
            return;
        }
    }
    cout<<"-1"<<'\n';
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









