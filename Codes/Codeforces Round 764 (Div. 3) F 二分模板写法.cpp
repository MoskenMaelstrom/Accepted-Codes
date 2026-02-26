#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve()
{
	int n;
	cin>>n;
	int l=1,r=n-1;
	
	int mid,premid=0;
	int ans,preans=0;
	int A;
	while (l <= r) {
		mid=(r+l)>>1;
		if (mid > premid) cout<<"+ "<<mid-premid<<endl;
		else cout<<"+ "<<n-premid+mid<<endl;
		cin>>ans;
		if (ans == preans) l=mid+1;	
		else A=mid,r=mid-1;
		preans=ans;
		premid=mid;
	}
	if (A > premid) cout<<"! "<<(ans+1)*n-A+premid<<endl;
	else cout<<"! "<<ans*n-A+premid<<endl;
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









