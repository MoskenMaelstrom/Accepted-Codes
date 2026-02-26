// Problem: C. Giving Directions in Harbin
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Harbin Onsite (The 3rd Universal Cup. Stage 14: Harbin)
// URL: https://codeforces.com/gym/105459/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	vector<pair<char,int>> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i].first;
		cin>>a[i].second;
	}
	
	vector<array<int,4>> d(4);
	d[0][2]=0;
	d[0][3]=1;
	d[1][3]=0;
	d[1][2]=1;
	d[2][1]=0;
	d[2][0]=1;
	d[3][0]=0;
	d[3][1]=1;
	map<char,int> mp;mp['N']=0;mp['S']=1;mp['W']=2;mp['E']=3;
	
	int m=2*n-1;
	cout<<m<<" "<<a[0].first<<"\n";
	cout<<"Z "<<a[0].second<<"\n";
	for(int i=1;i<n;i++) {
		auto [p,e1]=a[i-1];
		auto [cur,step]=a[i];
		int ok=d[mp[p]][mp[cur]];
		if (ok) cout<<"R\n";
		else cout<<"L\n";
		
		cout<<"Z "<<step<<"\n";
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









