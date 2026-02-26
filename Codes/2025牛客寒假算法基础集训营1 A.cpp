#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	bool flag=1;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i] == 1) flag=0;
	}
	
	if (!flag) cout<<"-1\n";
	else cout<<"999999999999999989"<<endl;
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









