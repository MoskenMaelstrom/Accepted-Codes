#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int a,b;
	cin>>a>>b;
	vector<int> ans;
	int maxn=0;
	auto work=[&](int x) {
		int cnt=0;
		while (x/10 != 0) {
			int t=x;
			int cur=1;
			while (t) {
				cur*=t%10;
				t/=10;
			}
			x=cur;
			cnt++;
		}
		return cnt;
	};

	for(int i=b;i>=a;i--) {
		int cnt=work(i);
		if (cnt > maxn) {
			ans.clear();
			ans.push_back(i);
			maxn=cnt;
		}
		else if (cnt == maxn) ans.push_back(i);
	}

	cout<<maxn<<"\n";
	cout<<ans[ans.size()-1];
	for(int i=ans.size()-2;i>=0;i--) cout<<" "<<ans[i];
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







