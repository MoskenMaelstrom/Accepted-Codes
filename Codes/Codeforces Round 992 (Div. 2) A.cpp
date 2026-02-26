#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
int a[205];
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	rep(i,n) cin>>a[i];
	rep(i,n) {
		bool flag=1;
		rep(j,n) {
			if (i != j and abs(a[i]-a[j])%k == 0) {flag=0;break;}//第二位赢了一次
		}
		if (flag) {cout<<"YES"<<endl<<i<<endl;return;}
	}
	cout<<"NO"<<endl;
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