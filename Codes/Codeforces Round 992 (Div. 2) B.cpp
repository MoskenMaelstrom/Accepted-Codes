#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int n,x=1,y=1;
	cin>>n;
	while (n > x) {x=(x+1)*2;y++;}
	cout<<y<<endl;
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