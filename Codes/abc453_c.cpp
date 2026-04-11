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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int maxn=0;
	for(int i=0;i<(1<<n);i++) {
		int cur=0;
		int cnt=0;
		for(int j=0;j<n;j++) {
			if ((i>>j)&1) {
				if (cur < 0 and cur+a[j] >= 0) cnt++;
				cur+=a[j];
			}
			else {
				if (cur >= 0 and cur-a[j] < 0) cnt++;
				cur-=a[j];
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
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







