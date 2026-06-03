// Problem: J. Roman Numerals
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/J
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
int c[]={1,5,10,50,100,500,1000};
void solve()
{
	int num;
	cin>>num;
	vector<int> a(10);
	vector<int> b(7);
	for(int i=0;i<10;i++) cin>>a[i];
	for(int i=0;i<7;i++) cin>>b[i];
	if (a[1] > b[0]) swap(a[1],b[0]);
	if (a[5] > b[1]) swap(a[5],b[1]);
	
	int ans=inf;
	auto dfs=[&](auto&& self,int x,int cost) -> void {
		if (cost >= ans) return;
		if (x == 0) {ans=min(ans,cost);return;}
		if (x%10 == 0) {
			for(int i=2;i<7;i++) {
				if (x < c[i]) break;
				self(self,(x-c[i])/10,cost+b[i]);
			}
			self(self,x/10,cost+a[0]);
		}
		else self(self,x/10,cost+a[x%10]);
	};
	dfs(dfs,num,0);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







