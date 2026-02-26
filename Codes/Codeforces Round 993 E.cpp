#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int k,l1,l2,r1,r2,ans=0;
	cin>>k>>l1>>r1>>l2>>r2;
	int kmax=0;
	while (1){
		if (pow(k,kmax) <= r2/l1) {kmax++;continue;}
		break;
	}
	kmax--;//k最多可以乘几次
	int chushu;
	int maxx;
	for(int i=0;i<=kmax;i++) {
		chushu=pow(k,i);//3的i次
		maxx=r2/chushu;
		maxx=min(r1,maxx);
		if (maxx-l1+1 > 0) ans+=maxx-l1+1;
		maxx=(l2-1)/chushu;
		maxx=min(r1,maxx);
		if (maxx-l1+1 > 0) ans-=maxx-l1+1;
	}
	cout<<ans<<endl;
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