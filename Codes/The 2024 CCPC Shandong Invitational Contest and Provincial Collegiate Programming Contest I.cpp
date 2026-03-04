// Problem: I. Left Shifting
// Contest: Codeforces - The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105385/problem/I
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int ans=-1;
	int l=0,r=n-1;
	for(int i=0;i<n;i++) {
		if (s[l] == s[r]) {ans=i;break;}
		l++,r++;
		l%=n,r%=n;
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







