// Problem: Iron Bars Cutting
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108298/I
// Memory Limit: 1024 MB
// Time Limit: 8000 ms
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

int ceil_log2(int x) {
    return (x <= 1) ? x : __lg(x-1)+1;
}

const int inf=1e18,N=421;
vector<int> f[N][N];
vector<array<int,3>> b[N][N];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+a[i];
	}
	
	auto cal=[&](int l,int r,int i) {
		return min(pre[i]-pre[l-1],pre[r]-pre[i])*ceil_log2(pre[r]-pre[l-1]);
	};
	
	for(int l=1;l<n;l++) {
		for(int r=l+1;r<=n;r++) {
			b[l][r].clear();
			b[l][r].resize(r-l);
			for(int i=l;i<r;i++) {
				b[l][r][i-l]={abs(pre[i]-pre[l-1]-(pre[r]-pre[i])),inf,i-l};
				// b[l][r].push_back({abs(pre[i]-pre[l-1]-(pre[r]-pre[i])),inf,i-l});
			}
            sort(b[l][r].begin(),b[l][r].end(),[](array<int,3> x,array<int,3> y){return x[0] < y[0];});
			// ranges::sort(b[l][r]);
		}
	}
	
	auto binary=[&](int l,int r,int sta) {
		if (l == r) return 0ll;
		int lo=0,hi=b[l][r].size()-1,res=-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			if (b[l][r][mid][0] <= sta) res=mid,lo=mid+1;
			else hi=mid-1;
		}
		return res;
	};
	
	for(int len=2;len<=n;len++) {	
		for(int l=1;l<=n-len+1;l++) {
			int r=l+len-1;
			f[l][r].clear();
			f[l][r].resize(r-l,inf);
			for(int i=l;i<r;i++) {
				int sta=abs(pre[i]-pre[l-1]-(pre[r]-pre[i]));
				int res=cal(l,r,i);
				int b1=binary(l,i,sta);
				int b2=binary(i+1,r,sta);
				if (b1 == -1 or b2 == -1) f[l][r][i-l]=inf;
				else {
					if (l != i) res+=b[l][i][b1][1];
					if (i+1 != r) res+=b[i+1][r][b2][1];
					f[l][r][i-l]=res;
				}
			}
			
			int minn=inf;
			for(auto &[bu,minx,idx] : b[l][r]) {
				minn=min(f[l][r][idx],minn);
				minx=minn;
			}
		}
	}
	
	for(int i=0;i<n-1;i++) {
		if (f[1][n][i] >= inf) cout<<"-1 ";
		else cout<<f[1][n][i]<<" ";
	}
	cout<<'\n';
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









