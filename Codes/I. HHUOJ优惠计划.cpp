#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while (t--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i<<=1){
			ans+=n/i;
		}
		cout<<ans<<endl;
	}
	
    return 0;
}