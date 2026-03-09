// Problem: G. Wafu!
// Contest: Codeforces - Codeforces Round 1042 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2131/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

int f[31];
const int p=1e9+7;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	int num=0,ans=1;
	for(int i=0;i<n;i++) {
		if (a[i] > 31 or 1<<(a[i]-1) > k) {
			num=a[i];
			break;
		}
		else {
			k-=1<<(a[i]-1);
			(ans*=f[a[i]])%=p;
		}
	}
	
	function<void(int)> dfs=[&](int x) {
		if (k == 0) return;
		k--;
		(ans*=x)%=p;
		for(int i=1;i<x;i++) {
			if (k == 0) return;
			if (i <= 31 and 1<<(i-1) <= k) k-=1<<(i-1),(ans*=f[i])%=p;
			else {dfs(i);return;}
		}
	};
	
	if (num) dfs(num);
	cout<<ans<<"\n";
}

signed main()
{
	int pre=1;
	for(int i=1;i<=30;i++) f[i]=i*pre%p,(pre*=f[i])%=p;
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







