// Problem: C. Dining Hall
// Contest: Codeforces - Codeforces Round 1012 (Div. 2)
// URL: https://codeforces.com/contest/2090/problem/C#
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	
	set<array<int,3>> st1,st2;
	for(int d=2;st1.size() <= n;d+=3) {
		for(int x=1;x<d;x+=3) {
			int y=d-x;
			st1.insert({d,x,y});
			st2.insert({d,x,y});
			st2.insert({d+1,x+1,y});
			st2.insert({d+1,x,y+1});
			st2.insert({d+4,x+1,y+1});
		}
	}
	
	
	for(int i=0;i<n;i++) {
		array<int,3> cur;
		if (a[i] == 0) cur=*st1.begin();
		else cur=*st2.begin();
		cout<<cur[1]<<" "<<cur[2]<<endl;
		st1.erase(cur);
		st2.erase(cur);
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









