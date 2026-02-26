#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int x,m,y,ans=0;
	cin>>x>>m;
	for(int i=1;i<=m;i++){
		y=i;
		int t=x^y;
		if (t%x == 0 or t%y == 0) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	int derta[1000]={0};
	int x,m,py=0,ans=0;
	cin>>x>>m;
	for (int i=1;i<=m;i++) {
		int y=i;
		int t=x^y;
		if (t%x == 0 or t%y == 0) {
			//cout<<x<<" "<<y<<" "<<t<<endl;
			derta[y-py]=1;
			py=y;
			ans++;
		}
	}
	cout<<"\n\n\n\n\n";
	cout<<ans;
	return 0;
}