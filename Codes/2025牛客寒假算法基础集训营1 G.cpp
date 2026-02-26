#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	int sum=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	int ans=(1+n)*n/2;
	if (sum != ans) {cout<<-1;return;}
	
	sort(a.begin(),a.end());
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (i+1 > a[i]) cnt+=i+1-a[i];
	}
	cout<<cnt;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}



// -1 3 4 4
// 1 2 3 4





