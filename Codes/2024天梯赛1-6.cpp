#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<double> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> cnt(n);
	while (1) {
		int id,c;
		cin>>id>>c;
		if (id == 0) break;
		id--;
		cnt[id]+=c;
	}
	double sum=0;
	for(int i=0;i<n;i++) sum+=a[i]*cnt[i];
	for(int i=0;i<n;i++) cout<<cnt[i]<<"\n";
	cout<<fixed<<setprecision(2)<<sum;

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







