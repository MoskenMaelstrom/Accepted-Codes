// Problem: I. Container Scheduling
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n,l,h;
	cin>>n>>l>>h;
	vector<int> X(1),Y(1);
	vector<array<int,4>> vec;
	for(int _=0;_<n;_++) {
		int x0,y0;
		cin>>x0>>y0;
		
		int x=inf,y=inf;
		for(auto x1 : X) {
			for(auto y1 : Y) {
				int x2=x1+x0;
				int y2=y1+y0;
				if (x2 > l or y2 > h) continue;
				bool f=1;
				for(auto [x3,y3,x4,y4] : vec) {
					if (max(x1,x3) < min(x2,x4) and max(y1,y3) < min(y2,y4)) {
						f=0;
						break;
					}
				}
				if (!f) continue;
				if (x > x1 or x == x1 and y > y1) x=x1,y=y1;
			}
		}
		
		if (x == inf) cout<<"-1\n";
		else {
			cout<<x<<" "<<y<<"\n";
			vec.push_back({x,y,x+x0,y+y0});
			X.push_back(x);
			X.push_back(x+x0);
			Y.push_back(y);
			Y.push_back(y+y0);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







