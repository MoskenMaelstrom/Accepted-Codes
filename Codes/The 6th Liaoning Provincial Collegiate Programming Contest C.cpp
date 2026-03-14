// Problem: C. Colorful logo
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/C
// Memory Limit: 512 MB
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
	string s1,s2;
	cin>>s1>>s2;
	int n1=0,n2=0;
	for(int i=0;i<3;i++) n1*=10,n1+=s1[i]-'0';
	for(int i=0;i<3;i++) n2*=10,n2+=s2[i]-'0';
	
	if (n1 <= n2) cout<<1;
	else cout<<0;
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







