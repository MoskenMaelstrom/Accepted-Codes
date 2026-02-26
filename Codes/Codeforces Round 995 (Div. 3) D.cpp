#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,x,y;
	int sum=0;
	cin>>n>>x>>y;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];}
	sort(a.begin()+1,a.begin()+n+1);
	
	int ans=0;
	for(int i=1;i<=n-1;i++) {
		int l=i;//枚举所有的l
		int r1,r2;//找到r的左右界
		
		r1=lower_bound(a.begin()+l+1,a.begin()+n+1,sum-y-a[l])-a.begin();
		r2=--upper_bound(a.begin()+l+1,a.begin()+n+1,sum-x-a[l])-a.begin();
		if (r2-r1 >= 0) ans+=r2-r1+1;
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