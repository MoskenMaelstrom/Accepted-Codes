#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	int bian=-1;
	for(int i=n-1;i>0;i--) {
		if (a[i] == a[i-1]) {bian=a[i];break;}
	}
	if (bian == -1) {cout<<-1<<endl;return;}
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (a[i] == bian) cnt++,a[i]=0;
		if (cnt == 2) break;
	}
	sort(a.begin(),a.end());
	vector<int> b(n);
	for(int i=2;i<n;i++) b[i]=a[i]-a[i-1];
	
	for(int i=3;i<n;i++) {
		if (abs(b[i])/2 < bian) {cout<<a[i]<<" "<<a[i-1]<<" "<<bian<<" "<<bian<<endl;return;}
	}
	cout<<-1<<endl;
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









