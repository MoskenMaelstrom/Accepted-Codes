#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const double eps=1e-9;
const double PI = acosl(-1.0);

int sign(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<double> ang(n);
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		ang[i]=atan2(y,x);
	}
	
	ranges::sort(ang);
	for(int i=0;i<n;i++) ang.push_back(ang[i]+2*PI);
	double ans=0;
	for(int i=0;i<n;i++) {
		ans=max(ans,ang[i+k]-ang[i]);
	}

	cout<<fixed<<setprecision(10)<<ans<<"\n";
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







