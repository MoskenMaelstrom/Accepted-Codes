// Problem: C - 2026
// Contest: AtCoder - AtCoder Beginner Contest 439
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

int Sqrt(int n) {
    int x=sqrt(n);
    if (x*x > n) {
        x--;
    }
    return x;
}

void solve()
{
	int n;
	cin>>n;
	unordered_map<int,int> mp;
	for(int i=1;i<sqrt(n);i++) {
		for(int j=i+1;j<sqrt(n);j++) {
			if (i*i+j*j <= n) mp[i*i+j*j]++;
		}
	}
	
	vector<int> ans;
	for(auto [e1,e2] : mp) {
		if (e2 == 1) ans.push_back(e1);
	}
	ranges::sort(ans);
	cout<<ans.size()<<"\n";
	for(auto e1 : ans) cout<<e1<<" ";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







