// Problem: D - Neighbor Distance
// Contest: AtCoder - AtCoder Beginner Contest 430
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	set<array<int,2>> st;//{x,closex}
	st.insert({0,inf});
	int ans=inf;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		if (st.upper_bound({x,0}) == st.end()) {
			auto it1=--st.end();
			auto [x1,cx1]=*it1;
			int x3=x;
			int cx3=x1;
			st.erase(it1);
			if (abs(x1-cx1) > abs(x1-x3)) {
				ans-=abs(x1-cx1);
				ans+=abs(x1-x3);
				cx1=x3;
			}
			ans+=abs(x3-cx3);
			st.insert({x1,cx1});
			st.insert({x3,cx3});
			cout<<ans<<"\n";
		}
		else if (st.upper_bound({x,0}) == st.begin()) {
			auto it2=st.begin();
			auto [x2,cx2]=*it2;
			int x3=x;
			int cx3=x2;
			st.erase(it2);
			if (abs(x2-cx2) > abs(x2-x3)) {
				ans-=abs(x2-cx2);
				ans+=abs(x2-x3);
				cx2=x3;
			}
			ans+=abs(x3-cx3);
			st.insert({x2,cx2});
			st.insert({x3,cx3});
			cout<<ans<<"\n";
		}
		else {
			auto it1=st.upper_bound({x,0});
			auto it2=prev(it1);
			auto [x1,cx1]=*it1;
			auto [x2,cx2]=*it2;
			int x3=x;
			int cx3=abs(x1-x3) > abs(x2-x3) ? x2 : x1;
			st.erase(it1);
			st.erase(it2);
			if (abs(x1-cx1) > abs(x1-x3)) {
				ans-=abs(x1-cx1);
				ans+=abs(x1-x3);
				cx1=x3;
			}
			if (abs(x2-cx2) > abs(x2-x3)) {
				ans-=abs(x2-cx2);
				ans+=abs(x2-x3);
				cx2=x3;
			}
			ans+=abs(x3-cx3);
			st.insert({x1,cx1});
			st.insert({x2,cx2});
			st.insert({x3,cx3});
			cout<<ans<<"\n";
		}
	}
	
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







