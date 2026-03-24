// Problem: B. 列车
// Contest: Codeforces - 第十三届重庆市大学生程序设计竞赛
// URL: https://codeforces.com/gym/105887/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	map<int,int> mp;
	mp[1]=0;
	mp[n]=inf;
	for(int i=1;i<=m;i++) {
		int l,r,c;
		cin>>l>>r>>c;
		mp[l]+=c;
		mp[r]-=c;
	}
	
	int cur=0;
	int ans=mp[1];
	for(auto [x,v] : mp) {
		cur+=v;
		ans=min(ans,cur);
	}
	cout<<ans<<"\n";
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







