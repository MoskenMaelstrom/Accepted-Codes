#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a.begin()+1,a.end());
	sort(b.begin()+1,b.end(),greater<int>());
	
	vector<int> sufa(n+1),sufb(n+1);
	sufa[n]=a[n],sufb[n]=b[n];
	for(int i=n-1;i>=0;i--) sufa[i]=sufa[i+1]+a[i];
	for(int i=n-1;i>=0;i--) sufb[i]=sufb[i+1]+b[i];
	
	int q;
	cin>>q;
	while (q--) {
		int t;
		cin>>t;
		
		int hi=n,lo=1,res=0;
		while (lo <= hi) {
			int mid=hi+lo>>1;
			if (a[mid] <= b[mid]*t) lo=mid+1;
			else hi=mid-1,res=mid;
		}
		
		cout<<max(0ll,sufa[res]-sufb[res]*t)<<" ";
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







