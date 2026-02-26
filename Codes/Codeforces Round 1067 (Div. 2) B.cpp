// Problem: B. Split
// Contest: Codeforces - Codeforces Round 1067 (Div. 2)
// URL: https://codeforces.com/contest/2158/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(2*n);
	map<int,int> mp;
	for(int i=0;i<2*n;i++) {
		cin>>a[i];
		mp[a[i]]++;
	}
	
	int c1=0,c4=0,c2=0;
	for(auto [num,c] : mp) {
		if (c%2 == 1) c1++;
		if (c%4 == 0) c4++;
		else if (c%2 == 0) c2++;
	}
	int ans=0;
	ans+=c1+c2*2;
	int cha4=0;
	if (c4%2 == 0) cha4=0;
	if (c4%2 == 1) cha4=2;
	
	if (cha4 == 0) ans+=c4*2;
	else {
		if (c1 >= 2) ans+=c4*2;
		else ans+=c4*2-2;
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







