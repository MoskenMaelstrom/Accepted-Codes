// Problem: D. Virtuous Pope
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	
	vector<array<int,3>> p1(n),p2(n);
	for(int i=0;i<n;i++) {
		cin>>p1[i][0]>>p1[i][1]>>p1[i][2];
		cin>>p2[i][0]>>p2[i][1]>>p2[i][2];
	}
	
	vector<array<int,2>> vec;
	for(int i=0;i<n;i++) {
		auto [x1,y1,z1]=p1[i];
		auto [x2,y2,z2]=p2[i];
		if (x1 < x2) vec.push_back({x1,1}),vec.push_back({x2+1,-1});
		else vec.push_back({x1+1,-1}),vec.push_back({x2,1});
	}
	ranges::sort(vec);
	int ans=0,cnt=0;
	for(auto [x,opt] : vec) {
		cnt+=opt;
		ans=max(cnt,ans);
	}
	
	vec.clear();
	for(int i=0;i<n;i++) {
		auto [x1,y1,z1]=p1[i];
		auto [x2,y2,z2]=p2[i];
		if (y1 < y2) vec.push_back({y1,1}),vec.push_back({y2+1,-1});
		else vec.push_back({y1+1,-1}),vec.push_back({y2,1});
	}
	ranges::sort(vec);
	cnt=0;
	for(auto [x,opt] : vec) {
		cnt+=opt;
		ans=max(cnt,ans);
	}
	
	vec.clear();
	for(int i=0;i<n;i++) {
		auto [x1,y1,z1]=p1[i];
		auto [x2,y2,z2]=p2[i];
		if (z1 < z2) vec.push_back({z1,1}),vec.push_back({z2+1,-1});
		else vec.push_back({z1+1,-1}),vec.push_back({z2,1});
	}
	ranges::sort(vec);
	cnt=0;
	for(auto [x,opt] : vec) {
		cnt+=opt;
		ans=max(cnt,ans);
	}
	
	cout<<ans;
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







