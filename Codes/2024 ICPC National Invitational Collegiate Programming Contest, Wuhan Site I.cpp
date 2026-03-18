// Problem: I. Cyclic Apple Strings
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/I
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int p=-1;
	for(int i=0;i<n;i++) {
		if (s[i] == '1') {p=i;break;}
	}
	if (p == -1) cout<<0<<"\n";
	else {
		int cnt=0;
		for(int i=p+1;i<n;i++) {
			if (s[i-1] == '1' and s[i] == '0') cnt++;
		}
		cout<<cnt<<"\n";
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







