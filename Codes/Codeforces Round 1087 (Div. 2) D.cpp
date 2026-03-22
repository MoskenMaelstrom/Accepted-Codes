// Problem: D. Ghostfires
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/contest/2209/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	vector<int> a(3);
	for(int i=0;i<3;i++) cin>>a[i];
	vector<int> ord(3);
	ranges::iota(ord,0);
	ranges::sort(ord,[&](int x,int y) {
		return a[x] < a[y];
	});
	// for(auto e1 : ord) cout<<e1<<" ";
	// cout<<endl;
	
	unordered_map<int,char> mp;
	mp[0]='R';
	mp[1]='G';
	mp[2]='B';
	
	string ans="";
	if (a[ord[2]] >= a[ord[1]]+a[ord[0]]+1) {
		for(int i=0;i<a[ord[1]];i++) ans+=mp[ord[2]],ans+=mp[ord[1]];
		for(int i=0;i<a[ord[0]];i++) ans+=mp[ord[2]],ans+=mp[ord[0]];
		ans+=mp[ord[2]];
	}
	else {
		int sum=a[ord[0]]+a[ord[1]]+a[ord[2]];
		if (sum&1) a[ord[1]]++;
		for(int i=0;i<(a[ord[1]]+a[ord[2]]-a[ord[0]])/2;i++) ans+=mp[ord[1]],ans+=mp[ord[2]];
		for(int i=0;i<(a[ord[0]]+a[ord[2]]-a[ord[1]])/2;i++) ans+=mp[ord[0]],ans+=mp[ord[2]];
		for(int i=0;i<(a[ord[0]]+a[ord[1]]-a[ord[2]])/2;i++) ans+=mp[ord[0]],ans+=mp[ord[1]];
		
		if (sum&1) ans.pop_back();
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







