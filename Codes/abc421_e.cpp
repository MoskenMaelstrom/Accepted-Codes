// Problem: E - Yacht/
// Contest: AtCoder - AtCoder Beginner Contest 421
// URL: https://atcoder.jp/contests/abc421/tasks/abc421_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	vector<int> a(6);
	for(int i=0;i<6;i++) cin>>a[i];
	
	map<pair<vector<int>,int>,double> mp;
	auto f=[&](auto self,vector<int> vec,int t) -> double {
		if (mp.count({vec,t})) return mp[{vec,t}];
		if (t == 0) {
			int res=0;
			map<int,int> cnt;
			for(auto idx : vec) cnt[a[idx]]++;
			for(auto [val,c] : cnt) res=max(res,val*c);
			return mp[{vec,t}]=res;
		}
		
		int n=5-vec.size(),m=1;
		for(int i=0;i<n;i++) m*=6;
		double sum=0;//全部情况的收益总和
		for(int S=0;S<m;S++) {
			int tmp=S;
			double Max=0;
			vector<int> add;
			for(int i=0;i<n;i++) add.push_back(tmp%6),tmp/=6;
			for(int bit=0;bit<(1<<n);bit++) {
				vector<int> cur=vec;
				for(int i=0;i<n;i++) if (bit&(1<<i)) cur.push_back(add[i]);
				Max=max(Max,self(self,cur,t-1));
			}
			sum+=Max;
		}
		return mp[{vec,t}]=sum/m;
	};
	
	cout<<fixed<<setprecision(10)<<f(f,{},3);
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









