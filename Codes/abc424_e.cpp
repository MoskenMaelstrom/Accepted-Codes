// Problem: E - Cut in Half
// Contest: AtCoder - AtCoder Beginner Contest 424
// URL: https://atcoder.jp/contests/abc424/tasks/abc424_e
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
	int n,k,x;
	cin>>n>>k>>x;
	multiset<pair<double,int>,greater<pair<double,int>>> st;
	for(int i=0;i<n;i++) {
		double val;
		cin>>val;
		st.insert({val,1});
	}
	
	while (1) {
		auto [val,num]=*st.begin();
		st.erase(st.begin());
		
		if (k-num <= 0) {
			if (num-k != 0) st.insert({val,num-k});
			st.insert({val/2,k*2});
			break;
		}
		k-=num;
		st.insert({val/2,num*2});
	}
	
	while (1) {
		auto [val,num]=*st.begin();
		st.erase(st.begin());
		
		if (x-num <= 0) {
			cout<<fixed<<setprecision(10)<<val<<"\n";
			break;
		}
		x-=num;
	}
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









