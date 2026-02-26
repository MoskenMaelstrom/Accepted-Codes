// Problem: D. Kevin and Numbers
// Contest: Codeforces - IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2061/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(auto &e1 : a) cin>>e1;
	for(auto &e1 : b) cin>>e1;
	multiset<int> c(a.begin(),a.end());
    auto work = [&](this auto &&self, int x) -> bool {
        if (x == 0) return 0;
        if (c.contains(x)) {
            c.erase(c.find(x));
            return 1;
        }
        return self(x / 2) and self(x - x / 2);
    };
    
    for (auto x : b) {
        if (!work(x)) {cout<<"No\n";return;}
    }
    if (c.empty()) cout<<"Yes\n";
    else cout<<"No\n";
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









