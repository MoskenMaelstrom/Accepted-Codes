#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005][2];
int mark[400005];
int mark1[400005];
int pre[400005];

void solve()
{
	int n,N1=1000000,N2=0;
	cin>>n;

	for(int i=1;i<=n;i++) {
		cin>>a[i][0]>>a[i][1];
		N1=min({N1,a[i][0],a[i][1]});
		N2=max({N2,a[i][0],a[i][1]});
	}
	
	for(int i=N1-1;i<=N2;i++) {
		mark[i]=0;
		mark1[i]=0;
		pre[i]=0;
	}
	
	for(int i=1;i<=n;i++) {
		if (a[i][0] == a[i][1]) {mark[a[i][0]]=1;mark1[a[i][0]]++;}
	}

	pre[N1]=mark[N1];
	for(int i=N1+1;i<=N2;i++) pre[i]=pre[i-1]+mark[i];
	
	for(int i=1;i<=n;i++) {
		if (a[i][1] == a[i][0] and mark1[a[i][0]] > 1) {cout<<0;continue;}
		if (a[i][1] == a[i][0] and mark1[a[i][0]] <= 1) {cout<<1;continue;}
		if (pre[a[i][1]] - pre[a[i][0]-1] == a[i][1]-a[i][0]+1) cout<<0;
		else cout<<1;
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