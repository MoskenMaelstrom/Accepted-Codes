// Problem: 小L的线段树
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

struct SegTree {
	int n;
	vector<int> mark;
	vector<int> cnt;
	SegTree(int n_) {
		n=n_;
		mark.resize(n*4);
		cnt.resize(n*4,1);
	}
	
	void Set(int v,int l,int r,int ql,int qr) {
		if (l == ql and r == qr) {mark[v]=1;cnt[v]=cnt[2*v]+cnt[2*v+1];return;}
		int m=l+r>>1;
		if (m >= ql) Set(2*v,l,m,ql,qr);
		else Set(2*v+1,m+1,r,ql,qr);
		
		if (mark[v]) cnt[v]=cnt[2*v]+cnt[2*v+1];
	}
	
	int query(int v,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return 0;
		if (ql <= l and r <= qr) return cnt[v];
		return (mark[v] == 0)+query(2*v,l,l+r>>1,ql,qr)+query(2*v+1,(l+r>>1)+1,r,ql,qr);
	}
};
	
void solve()
{
	int n;
	cin>>n;
	SegTree st(n);
	for(int i=0;i<n;i++) {
		int opt,l,r;
		cin>>opt>>l>>r;
		l--,r--;
		if (opt == 1) st.Set(1,0,n-1,l,r);
		else cout<<st.query(1,0,n-1,l,r)<<"\n";
	}
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







