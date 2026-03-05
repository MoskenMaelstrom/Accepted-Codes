// Problem: K. 小 C 的神秘图形
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Chongqing Onsite
// URL: https://codeforces.com/gym/106030/problem/K
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++) {
		if (s1[i] != '1' and s2[i] != '1') {
			cout<<0;
			return;
		}
	}
	cout<<1;
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







