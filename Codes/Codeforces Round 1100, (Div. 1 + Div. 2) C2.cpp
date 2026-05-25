// Problem: C2. We Be Flipping (Hard Version)
// Contest: Codeforces - Spectral::Cup 2026 Round 2 (Codeforces Round 1100, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2229/problem/C2
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+2);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+abs(a[i]);
	vector<int> suf(n+2);
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
	
	int maxn=suf[1];
	int id=0;
	for(int i=1;i<=n;i++) {
		if (a[i] <= 0) continue;
		int t=pre[i-1]-a[i]+suf[i+1];
		if (t > maxn) {
			maxn=t;
			id=i;
		}
	}
	
	if (id == 0) {
		cout<<"0\n\n";
		return;
	}
	
	vector<int> ans;
	int f=1;
	for(int i=id-1;i>=1;i--) {
		if (a[i]*f > 0) ans.push_back(i),f=-f;
	}
	ans.push_back(id);
	cout<<ans.size()<<"\n";
	for(auto e1 : ans) cout<<e1<<" ";
	cout<<"\n";
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







