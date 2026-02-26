// Problem: D. Price Tags
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int N=2e5;
const int inf=1e18;
void solve()
{
	int n,y;
	cin>>n>>y;
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];
	vector<int> tong(N+1);
	for(int i=0;i<n;i++) tong[c[i]]++;
	vector<int> pre(N+1);
	for(int i=1;i<=N;i++) pre[i]=pre[i-1]+tong[i];
	
	int ans=-inf;
	for(int x=2;x<=N;x++) {
		int sum=0,cnt=0;
		for(int p=1;;p++) {
			int l=(p-1)*x+1;
            int r=p*x;
            if (l > N) break;
            if (l > r) continue;	
            r=min(r,N);
            int d=pre[r]-pre[l-1];
            if (d == 0) continue;
            sum+=d*p;
            int s=p <= N ? tong[p] : 0;
            cnt+=min(d,s);
		}
		ans=max(ans,sum-y*(n-cnt));
	}
	cout<<ans<<"\n";
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









