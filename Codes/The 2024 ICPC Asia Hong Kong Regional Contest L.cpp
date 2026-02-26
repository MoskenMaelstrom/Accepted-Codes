#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char c;
			cin>>c;
			if (c == 'B') a[i][j]=1;
		}
	}
	
	vector<string> ans;
	auto work=[&](int tar) -> void {
		auto vec=a;
		auto check=[&]() -> bool {
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if (vec[i][j] != tar) return 0;
				}
			}
			return 1;
		};
		auto findr=[&](int x) -> int {
			for(int y=m-1;y>=0;y--) {
				if (vec[x][y] != tar) return y;
			}
			return -1;
		};
		
		while (ans.size() <= 400) {
			if (check()) break;
			string res="";
			int y=0;
			for(int x=0;x<n;x++) {
				int r=findr(x);
				if (y > r) {
					vec[x][y]^=1;
				}
				else {
					vec[x][y]^=1;
					for(int j=y+1;j<=r;j++) res+="R",vec[x][j]^=1;
					y=r;
				}
				
				if (x == n-1) {
					for(int j=y+1;j<m;j++) res+="R",vec[x][j]^=1;
				}
				else res+="D";
			}
			ans.push_back(res);
		}
	};
	
	work(0);
	if (ans.size() > 400) {ans.clear();work(1);}
	if (ans.size() > 400) cout<<"NO\n";
	else {
		cout<<"YES\n";
		cout<<ans.size()<<"\n";
		for(auto e1 : ans) cout<<e1<<"\n";
	}
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







