#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n+5,-1);
	vector<int> b(n+5,-1);
	for(int i=1;i<=m;i++) cin>>a[i];//不会考的题
	for(int i=1;i<=k;i++) cin>>b[i];//我会的题
	
	if (n > k+1) {for(int i=0;i<m;i++) cout<<0; cout<<"\n";return;}
	if (n == k) {for(int i=0;i<m;i++) cout<<1; cout<<"\n";return;}
	
	int num=n;
	for(int i=1;i<=k;i++) if (b[i] != i) {num=i;break;}
	for(int i=1;i<=m;i++) {
		if (i == num) cout<<1;
		else cout<<0;
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}