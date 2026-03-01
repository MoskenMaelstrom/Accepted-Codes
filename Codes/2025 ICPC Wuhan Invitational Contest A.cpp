// Problem: A. Problem Setting
// Contest: Codeforces - 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
// URL: https://codeforces.com/gym/105901/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<int> L(n,-inf),R(n,inf);
	for(int i=0;i<q;i++) {
		int p,l,r;
		cin>>p>>l>>r;
		p--;
		L[p]=max(L[p],l);
		R[p]=min(R[p],r);
	} 
	
	int ok=1;
	int ans=0;
	for(int i=0;i<n;i++) {
		if (L[i] > R[i]) ok=0;
		if (L[i] > a[i] or R[i] < a[i]) ans+=min(abs(L[i]-a[i]),abs(R[i]-a[i]));
	}
	if (ok) cout<<ans<<"\n";
	else cout<<"-1\n";
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







