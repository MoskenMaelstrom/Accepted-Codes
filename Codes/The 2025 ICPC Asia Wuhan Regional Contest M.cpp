#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=998244353;	
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector vec(n+1,vector<int>(n+1));
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if (i == j) vec[i][j]=a[j]+1;
			else vec[i][j]=a[j];
		}
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<(vec[i][j]%p+p)%p<<" ";
		}
		cout<<"\n";
	}
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







