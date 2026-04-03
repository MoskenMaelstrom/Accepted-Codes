#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	auto check=[&](vector<vector<int>>& a) -> bool {
		vector<bool> mark(10);
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				mark[a[i][j]]=1;
			}
		}
		return (ranges::count(mark,1) == 9);
	};

	bool ok=1;
	vector a(9,vector<int>(9));
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			cin>>a[i][j];
			if (a[i][j] < 1 or a[i][j] > 9) ok=0;
		}
	}

	if (!ok) {
		cout<<"0\n";
		return;
	}

	for(int i=0;i<9;i+=3) {
		vector<vector<int>> b(3,vector<int>(3));
		for(int j=0;j<9;j+=3) {
			for(int k=0;k<3;k++) {
				for(int l=0;l<3;l++) {
					b[k][l]=a[i+k][j+l];
				}
			}
		}
		if (!check(b)) ok=0;
	}

	for(int i=0;i<9;i++) {
		vector<bool> mark(10);
		for(int j=0;j<9;j++) mark[a[i][j]]=1;
		if (ranges::count(mark,1) != 9) ok=0;
	}

	for(int j=0;j<9;j++) {
		vector<bool> mark(10);
		for(int i=0;i<9;i++) mark[a[i][j]]=1;
		if (ranges::count(mark,1) != 9) ok=0;
	}

	if (ok) cout<<"1\n";
	else cout<<"0\n";
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







