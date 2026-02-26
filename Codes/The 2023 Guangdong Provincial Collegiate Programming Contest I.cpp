#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> tong(n*m);
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			tong[a[i][j]]={i,j};
		}
	}
	
	auto check=[&](int num) {
		vector<array<int,2>> vec(num);
		for(int i=0;i<num;i++) {
			vec[i]=tong[i];
		}
		ranges::sort(vec);
		for(int i=0;i<num-1;i++) {
			if (vec[i][1] > vec[i+1][1]) return 0;
		}
		return 1;
	};
	
	int lo=0,hi=n*m,res=-1;
	while (lo <= hi)
	{
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,lo=mid+1;
		else hi=mid-1;
	}
	cout<<res<<endl;
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









