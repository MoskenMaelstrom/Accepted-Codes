#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int run(int x) {
	int res=0;
	while (x != 0) {
		res+=x/4;
		x/=4;
		res-=x/25;
		x/=25;
	}
	return res;
}

void solve()
{
	int n;
	cin>>n;
	int base=2024-run(2024);
	int l=0,r=2e18,ans;
	while (l <= r) {
		int mid=l+r>>1;
		if (mid-run(mid)-base >= n) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
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









