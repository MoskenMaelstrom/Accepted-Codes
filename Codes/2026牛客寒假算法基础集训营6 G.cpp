// Problem: 小L的散步
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m,l;
	cin>>n>>m>>l;
	vector<int> a(n),b(m+1);
	b[0]=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	int sum1=0,sum2=0;
	int p=0;
	bool ok=0;
	for(int i=0;i<=m;i++) {
		sum1+=b[i];
		while (p < n and sum2 <= sum1) sum2+=a[p],p++;
		if (sum2 > sum1 and sum2 < sum1+l) {ok=1;break;}
	}
	if (ok) cout<<"YES";
	else cout<<"NO";
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







