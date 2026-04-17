#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

double cur=0;
const double limit=0.28;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	ranges::sort(vec);
	
	vector<int> a;
	vector<int> ans;
	int step=0;
	auto dfs=[&](auto&& self,int sum,int id) {
		step++;
		if (step%1000 == 0) {
			cur=(double)clock()/CLOCKS_PER_SEC;
			if (cur > limit) return;
		}
		if (!ans.empty() or cur > limit) return;
		if (sum == m and ans.empty()) {
			ans=a;
			return;
		}
		else if (sum > m) return;
		
		for(int i=id+1;i<n;i++) {
			a.push_back(vec[i]);
			self(self,sum+vec[i],i);
			a.pop_back();
		}
	};
	
	for(int i=0;i<n;i++) {
		a.push_back(vec[i]);
		dfs(dfs,vec[i],i);
		a.pop_back();
	}
	
	if (ans.empty()) cout<<"No Solution";
	else {
		bool ok=1;
		for(auto e1 : ans) {
			if (ok) {cout<<e1;ok=0;}
			else cout<<" "<<e1;
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







