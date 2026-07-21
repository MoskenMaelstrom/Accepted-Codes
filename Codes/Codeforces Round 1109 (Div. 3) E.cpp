// Problem: E. Masha and the Garland
// Contest: Codeforces - Codeforces Round 1109 (Div. 3)
// URL: https://codeforces.com/contest/2244/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	s=" "+s;
	vector<bool> f1(n+1),f2(n+1);
	for(int i=1;i<=n;i++) {
		if ((i&1) == s[i]-'0') f1[i]=1;
		else f2[i]=1;
	}
	vector<int> pre1(n+1),pre2(n+1);
	for(int i=1;i<=n;i++) {
		if (f1[i] and !f1[i-1]) pre1[i]++;
		if (f2[i] and !f2[i-1]) pre2[i]++;
		pre1[i]+=pre1[i-1];
		pre2[i]+=pre2[i-1];
	}
	
	// for(auto e1 : pre1) cout<<e1<<" ";
	// cout<<endl;
	// for(auto e2 : pre2) cout<<e2<<" ";
	// cout<<endl;
	
	while (q--) {
		int l,r,k;
		cin>>l>>r>>k;
		int ans1=pre1[r]-pre1[l-1];
		if (f1[l] == 1 and f1[l-1] == 1) ans1++;
		int ans2=pre2[r]-pre2[l-1];
		if (f2[l] == 1 and f2[l-1] == 1) ans2++;
		int ans=min(ans1,ans2);
		// cout<<ans1<<" "<<ans2<<"\n";
		if (k >= ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







