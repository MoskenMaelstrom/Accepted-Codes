// Problem: A. Project Management
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/A
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector vec(n+1,vector<array<int,2>>(0));
	for(int i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		vec[a].push_back({b,i+1});
	}
	for(int i=1;i<=n;i++) ranges::sort(vec[i]);
	
	bool ok=0;
	auto check=[&](int x) -> bool {
		int s=x;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<vec[i].size();j++) {
				if (x-(vec[i].size()-j) <= vec[i][j][0]) {
					x-=vec[i].size()-j;
					if (ok) {
						for(int k=j;s and k<vec[i].size();s--,k++) cout<<vec[i][k][1]<<" ";
					}
					break;
				}
			}
		}
		if (ok) cout<<"\n";
		return x <= 0;
	};
	
	int lo=1,hi=n,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,lo=mid+1;
		else hi=mid-1;
	}
	ok=1;
	cout<<res<<"\n";
	check(res);
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







