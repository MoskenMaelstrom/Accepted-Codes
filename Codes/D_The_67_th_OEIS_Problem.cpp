#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e6;
vector<bool> isp(N+1,1);
vector<int> vec;
void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cout<<vec[i]*vec[i+1]*vec[i+2]<<" ";
	}
	cout<<"\n";
}

signed main()
{
	isp[0]=isp[1]=0;
	for(int i=2;i<=N;i++) {
		if (!isp[i]) continue;
		for(int j=i;i*j<=N;j++) isp[i*j]=0;
	}
	for(int i=2;i<=N;i++) {
		if (isp[i]) vec.push_back(i);
	}
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







