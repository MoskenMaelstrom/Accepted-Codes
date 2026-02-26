// Problem: A. Adrenaline Rush
// Contest: Codeforces - 2024-2025 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)2024-2025 ICPC, NERC, 北欧亚地区决赛（未评级，在线镜像，ICPC 规则，优先考虑团队）
// URL: https://codeforces.com/problemset/problem/2052/A
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
	}
	
	vector<array<int,2>> ans;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-1-i;j++) {
			if (a[j] < a[j+1]) {
				ans.push_back({a[j],a[j+1]});
				swap(a[j],a[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-1-i;j++) {
			if (a[j] > a[j+1]) {
				ans.push_back({a[j],a[j+1]});
				swap(a[j],a[j+1]);
			}
		}
	}
	
	ranges::reverse(ans);
	cout<<ans.size()<<endl;
	for(auto [e1,e2] : ans) cout<<e1+1<<" "<<e2+1<<endl;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









