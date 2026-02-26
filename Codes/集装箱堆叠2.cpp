#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=1e9+7;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector pre1(n+1,vector<int>(m+1));
	vector pre2(n+1,vector<int>(m+1));
	for(int j=1;j<=m;j++) {
		int r=min(j,n);
		for(int i=1;i<=r;i++) {
			int cur=0;
			if (j-i == 0) cur=1;
			else {
				cur=(i+1)*pre1[i][j-i]-pre2[i][j-i];
				cur%=p;
			}
			pre1[i][j]=pre1[i-1][j]+cur;
			pre1[i][j]%=p;
			pre2[i][j]=pre2[i-1][j]+cur*i;
			pre2[i][j]%=p;
		}
		for(int i=r+1;i<=n;i++) {
			pre1[i][j]=pre1[i-1][j];
			pre2[i][j]=pre2[i-1][j];
		}
	}
	
	cout<<(pre1[n][m]-pre1[n-1][m]+p)%p;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







