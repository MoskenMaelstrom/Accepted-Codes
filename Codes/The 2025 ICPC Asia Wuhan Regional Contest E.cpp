#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	ranges::sort(a);
	ranges::sort(b);
	if (a == b) {cout<<"Yes\n";return;}
	
	int ok=0;
	for(int i=0;i<n-1;i++) {
		if (a[i]+1 == a[i+1]) {ok++;break;}
	}
	for(int i=0;i<n-1;i++) {
		if (b[i]+1 == b[i+1]) {ok++;break;}
	}
	
	if (ok != 2) {cout<<"No\n";return;}
	
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++) {
		if (a[i]%2) sum1++;
		if (b[i]%2) sum2++;
	}
	if (sum1 != sum2) {cout<<"No\n";return;}
	
	cout<<"Yes\n";
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







