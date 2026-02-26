// Problem: P2742 [USACO5.1] 圈奶牛Fencing the Cows /【模板】二维凸包
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2742
// Memory Limit: 128 MB
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
// #define int long long
using namespace std;

double cross(const array<double,2> &a, const array<double,2> &b, const array<double,2> &c) {
	return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
}

double dis(const array<double,2> &a, const array<double,2> &b) {
	return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

vector<array<double,2>> andrew(vector<array<double,2>> &a) {
	ranges::sort(a);
	vector<array<double,2>> l,h;
	for(auto p : a) {
		while (l.size() > 1 and cross(l[l.size()-2],l.back(),p) <= 0) l.pop_back();
		while (h.size() > 1 and cross(h[h.size()-2],h.back(),p) >= 0) h.pop_back();
		l.push_back(p);
		h.push_back(p);
	}
	ranges::reverse(h);
	h.insert(h.end(),l.begin()+1,l.end());
	return h;
}

void solve()
{
	int n;
	cin>>n;
	vector<array<double,2>> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1];
	}
	
	auto hull=andrew(a);
	double ans=0;
	for(int i=0;i<hull.size()-1;i++) {
		ans+=dis(hull[i],hull[i+1]);
	}
	cout<<fixed<<setprecision(2)<<ans;
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









