#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve()
{
	int n;
	cin>>n;
	int l=0,r=n;
	
	int mid,premid=0;
	int ans,preans=0;
	
	while (r-l > 1) {
		mid=(r+l)>>1;
		if (mid > premid) cout<<"+ "<<mid-premid<<endl;
		else cout<<"+ "<<n-premid+mid<<endl;
		cin>>ans;
		if (ans == preans) l=mid;
		else r=mid;
		preans=ans;
		premid=mid;
	}
	if (r > premid) cout<<"! "<<(ans+1)*n-r+premid<<endl;
	else cout<<"! "<<ans*n-r+premid<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









