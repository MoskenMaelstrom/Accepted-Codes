#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	ranges::sort(a);
	ranges::sort(b);
	int k=ranges::count(a,1) != 0;
	for(int i=0;i<n;i++) {
		if (a[i] != 1) k++;
		a[i]--;
	}

	int p1=0,p2=0;
	int cnt=0;
	while (p1 < n or p2 < m) {
		if (p1 < n and a[p1] <= cnt) {
			cnt++;
			p1++;
		}
		else if (p2 < m and b[p2] <= cnt) {
			cnt++;
			p2++;
		}
		else if (p2 < m) {
			if (k >= b[p2]-cnt) {
				k-=b[p2]-cnt;
				cnt++;
				p2++;
			}
			else break;
		}
		else break;
	}
	if (p2 == m) cout<<"Yes\n";
	else cout<<"No\n";
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







