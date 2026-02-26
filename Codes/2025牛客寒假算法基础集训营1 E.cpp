#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	int A=a[n/4+1];
	int B=a[n/2+n/4+1];
	
	int ans=0;
	if (A != B) {
		for(int i=1;i<=n/2;i++) ans+=abs(a[i]-A);
		for(int i=n/2+1;i<=n;i++) ans+=abs(a[i]-B);
	}
	else {
		int ans1=0;
		int ans2=0;
		A--;
		for(int i=1;i<=n/2;i++) ans1+=abs(a[i]-A);
		for(int i=n/2+1;i<=n;i++) ans1+=abs(a[i]-B);
		
		A++;
		B++;
		for(int i=1;i<=n/2;i++) ans2+=abs(a[i]-A);
		for(int i=n/2+1;i<=n;i++) ans2+=abs(a[i]-B);
		
		ans=min(ans1,ans2);
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






