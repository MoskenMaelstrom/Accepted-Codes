// Problem: F. Inversion Pairs
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/F
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i] != '0');
	int ans=0;
	for(int i=n;i>=1;i--) {
		if (s[i] == '0') ans+=pre[i];
	}
	
	int cur=ans;
	int c0=0;
	for(int i=n;i>=1;i--) {
		if (s[i] == '0') c0++;
		if (s[i] == '?') cur-=c0,cur+=pre[i-1],c0++;
		ans=max(ans,cur);
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







