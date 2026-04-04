#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),b(m+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	int sum1=0;
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) {
		pre[i]=(pre[i-1]+a[i])%p;
		(sum1+=i*a[i])%=p;
	}
	int sum2=0;
	for(int i=1;i<=m;i++) {
		(sum2+=b[i])%=p;
	}

	int ans=sum1*sum2%p;
	for(int j=1;j<=m;j++) {
		int sum=0;
		for(int k=1;k*j<=n;k++) {
			int l=k*j;
			int r=min(n,(k+1)*j-1);
			(sum+=k*(pre[r]-pre[l-1])%p)%=p;
		}
		(ans-=j*b[j]%p*sum%p)%=p;
	}
	cout<<(ans+p)%p<<"\n";
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







