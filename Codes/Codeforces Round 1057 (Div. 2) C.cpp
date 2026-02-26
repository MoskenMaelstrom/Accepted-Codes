// Problem: C. Symmetrical Polygons
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/contest/2153/problem/C
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		mp[a[i]]++;
	}
	
	int cnt=0;
	int ans=0;
	for(auto& [e1,e2] : mp) {
		if (e2%2 == 0) ans+=e1*e2,cnt+=e2,e2=0;
		else ans+=e1*(e2-1),cnt+=e2-1,e2=1;
	}
	
	vector<int> vec;
	for(auto& [e1,e2] : mp) {
		if (e2 != 0) vec.push_back(e1);
	}
	
	int res=ans;
	ranges::sort(vec);
	// for(auto e1 : vec) cout<<e1<<" ";
	// cout<<endl;
	
	for(int i=0;i<vec.size();i++) {
		if (vec[i] < ans) res=max(res,ans+vec[i]);
		else break;
	}
	
	for(int i=0;i+1<vec.size();i++) {
		if (vec[i+1]-vec[i] < ans) res=max(res,ans+vec[i]+vec[i+1]);
	}
	
	if (cnt == 2 and res == ans) cout<<"0\n";
	else cout<<res<<"\n";
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









