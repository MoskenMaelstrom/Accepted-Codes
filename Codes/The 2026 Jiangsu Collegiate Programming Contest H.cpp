// Problem: H. Treasure Island
// Contest: Codeforces - The 2026 Jiangsu Collegiate Programming Contest, The 2026 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106550/problem/H
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<array<int,2>> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i][0]>>vec[i][1];
	map<int,int> mp;
	set<array<int,2>,greater<array<int,2>>> st;
	int s=0;
	for(int i=0;i<n;i++) {
		auto [opt,x]=vec[i];
		if (opt == 1) mp[i]=x;
		else if (opt == 2) s+=x;
		else {
			while (!mp.empty() and x >= k) {
				auto &[t,cnt]=*mp.rbegin();
				int cur=x/k;
				x-=min(cnt,cur)*k;
				if (cnt <= cur) mp.erase(--mp.end());
				else cnt-=cur;
			}
			
			if (x) {
				s-=x;
				st.insert({x,i});
			}
			
			while (!st.empty() and s < 0) {
				auto [cnt1,t1]=*st.begin();
				st.erase(st.begin());
				auto it=mp.upper_bound(t1);
				if (it == mp.begin()) continue;
				it--;
				s+=cnt1;
				auto &[t2,cnt2]=*it;
				if (cnt2 == 1) mp.erase(it);
				else cnt2--;
			}
			
			if (s < 0) {
				cout<<"-1\n";
				return;
			}
		}
	}
	
	for(auto [t,cnt] : mp) s+=cnt*k;
	cout<<s<<"\n";
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







