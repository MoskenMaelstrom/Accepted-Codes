#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=998244353;
int pow(int base,int exp) {
	int res=1;
	base%=p;
	while (exp > 0) {
		if (exp%2 == 1) res=(res*base)%p;
		exp>>=1;
		base=(base*base)%p;
	}
	return res;
}

int ny(int num) {
	return pow(num,p-2)%p;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	int ans=a[0]%p;
	for(int i=1;i<n;i++) {
		ans*=2;
		ans%=p;
		ans+=a[i]*((pow(3ll,i)-1+p)%p*ny(2ll)%p+1)%p;
		ans%=p;
	}
	cout<<ans<<"\n";
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