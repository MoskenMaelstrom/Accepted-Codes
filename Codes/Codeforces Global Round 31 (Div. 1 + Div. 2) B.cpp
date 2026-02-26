// Problem: B. Ashmal
// Contest: Codeforces - Codeforces Global Round 31 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2180/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	string ans="";
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		string cur1=s+ans;
		string cur2=ans+s;
		ans=min(cur1,cur2);
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







