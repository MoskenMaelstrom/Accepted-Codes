// Problem: B. Binary Typewriter
// Contest: Codeforces - Codeforces Round 1019 (Div. 2)
// URL: https://codeforces.com/contest/2103/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	string s;
	cin>>s;
	int cnt0=0,cnt1=0;
	for(int e1 : s) {
		if (e1 == '0') cnt0++;
		else cnt1++;
	}
	int c1=0,c2=0;
	for(int i=0;i<n-1;i++) {
		if (s[i] == '1' and s[i+1] == '0') c1++;
		if (s[i] == '0' and s[i+1] == '1') c2++;
	}
	int cost=0;
	for(int i=0;i<n-1;i++) {
		if (s[i] != s[i+1]) cost++;
	}
	
	if (s[0] == '1') cost++;
	if (cnt1 == 0 or cnt0 == 0) {cout<<n+cost<<endl;return;}
	
	if (c1 >= 1 and c2 >= 1 and (c1>=2 or c2>=2)) {
		cout<<n+cost-2<<endl;
	}
	else if (c1 >= 1 and c2 >= 1 and s[0] == '1') cout<<n+cost-2<<endl;
	else if (c1 >= 1 and c2 >= 1 and s[0] == '0') cout<<n+cost-1<<endl;
	else {
		if (s[0] == '1') cout<<n+cost-1<<endl;
		else cout<<n+cost<<endl;
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









