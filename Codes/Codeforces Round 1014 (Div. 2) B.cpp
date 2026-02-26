// Problem: B. Lady Bug
// Contest: Codeforces - Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/contest/2092/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	string s1,s2;
	cin>>s1>>s2;
	int c1=0,c2=0,c3=0,c4=0;
	for(int i=0;i<n;i+=2) {
		if (s1[i] == '1') c1++;
		if (s2[i] == '0') c3++;
	}
	for(int i=1;i<n;i+=2) {
		if (s1[i] == '1') c2++;
		if (s2[i] == '0') c4++;
	}
	// cout<<c1<<" "<<c2<<endl;
	if (c1 <= c4 and c2 <= c3) cout<<"YES\n";
	else cout<<"NO\n";
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









