// Problem: D. Copy String
// Contest: Codeforces - Codeforces Global Round 30 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2164/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	string a,b;
	cin>>a>>b;
	
	vector<array<int,2>> sta;
	vector<int> link(n,-1);
	for(int i=0;i<n;i++) sta.push_back({a[i]-'a',i});
	for(int i=n-1;i>=0;i--) {
		while (!sta.empty() and (sta.back()[0] != b[i]-'a' or i < sta.back()[1])) sta.pop_back();
		if (sta.empty()) break;
		
		link[i]=i-sta.back()[1];
	}
	
	if (*ranges::min_element(link) == -1) cout<<"-1\n";
	else {
		vector<string> ans;
		while (a != b and ans.size() <= k) {
			auto a1=a;
			for(int i=0;i<n;i++) {
				if (link[i] == 0) continue;
				a1[i-link[i]+1]=a[i-link[i]];
				link[i]--;
			}
			ans.push_back(a1);
			a=a1;
		}
		if (ans.size() > k) cout<<"-1\n";
		else {
			cout<<ans.size()<<"\n";
			for(auto e1 : ans) cout<<e1<<"\n";
		}
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







