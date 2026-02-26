// Problem: 墨提斯的排列
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(2);
	a[0]=0,a[1]=1;
	for(int i=1;i<n;i++) {
		auto vec=a;
		ranges::reverse(vec);
		for(int j=0;j<vec.size();j++) a.push_back(vec[j]);
		for(int j=vec.size();j<a.size();j++) a[j]|=1<<i;
	}
	for(auto e1 : a) cout<<e1<<" ";
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







