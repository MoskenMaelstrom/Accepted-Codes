#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int n=s.length();
	int a[200005];
	rep(i,n) a[i]=s[i]-48;
	rep(i,10) {
		for(int i=1;i<n;i++){
			if (a[i]-1 > a[i-1]) {a[i]--;swap(a[i],a[i-1]);}
		}
	}
	rep(i,n) cout<<a[i];
	cout<<endl;
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