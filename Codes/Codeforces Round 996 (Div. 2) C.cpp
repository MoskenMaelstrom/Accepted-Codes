#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n+5,vector<int>(m+5));
	vector<vector<int>> mark(n+5,vector<int>(m+5));
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	
	int x=1,y=1;//搜索一边补全
	int X=0;
	for(auto ele : s) {
		int sum=0;
		if (ele == 'D') {
			for(int j=1;j<=m;j++) sum+=a[x][j];
			a[x][y]=X-sum;
			x++;
		}
		else {
			for(int i=1;i<=n;i++) sum+=a[i][y];
			a[x][y]=X-sum;
			y++;
		}
	}
	//最后一个处理一下
	int sum=0;
	for(int j=1;j<=m;j++) sum+=a[x][j];
	a[x][y]=X-sum;
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
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