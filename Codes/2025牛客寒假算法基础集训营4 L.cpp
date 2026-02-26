// Problem: Tokitsukaze and XOR-Triangle
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/L
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=1e9+7;
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	vector prea(n+1,vector<int>(31)),preb(n+1,vector<int>(31));
	for(int i=1;i<=n;i++) {
		for(int j=0;j<31;j++) {
			prea[i][j]=prea[i-1][j]+((a[i]>>j)&1);
			preb[i][j]=preb[i-1][j]+((b[i]>>j)&1);
		}
	}
	
	auto query=[&](int x1,int x2,int y1,int y2) -> int {
		if (y1 > y2) return 0;
		int res=0;
		for(int j=0;j<31;j++) {
			res+=(prea[x2][j]-prea[x1-1][j])*(y2-y1+1-(preb[y2][j]-preb[y1-1][j]))<<j;
			res%=p;
			res+=(x2-x1+1-(prea[x2][j]-prea[x1-1][j]))*(preb[y2][j]-preb[y1-1][j])<<j;
			res%=p;
		}
		return res;
	};
	
	vector<int> pred(n+1);
	for(int i=1;i<=n;i++) {
		int cnt=0;
		for(int j=0;j<31;j++) {
			cnt+=(((a[i]>>j)&1)^1)*(preb[n][j]-preb[i-1][j])<<j;
			cnt%=p;
			cnt+=(((a[i]>>j)&1)^0)*(n-i+1-preb[n][j]+preb[i-1][j])<<j;
			cnt%=p;
		}
		pred[i]=pred[i-1]+cnt;
		pred[i]%=p;
	}
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		cout<<((pred[r]-pred[l-1]+p)%p-query(l,r,r+1,n)+p)%p<<endl;
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









