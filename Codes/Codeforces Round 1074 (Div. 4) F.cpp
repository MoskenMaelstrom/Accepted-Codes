// Problem: F. BattleCows
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
struct Info {
	int sum,Max,Min,Gcd,Xor;
	Info() : sum(0),Max(-inf),Min(inf),Gcd(0),Xor(0) {};
    Info(int val) : sum(val),Max(val),Min(val),Gcd(val),Xor(val) {};
    Info operator+(const Info &other) const {
    	Info res;
    	res.sum=sum+other.sum;
    	res.Min=min(Min,other.Min);
    	res.Max=max(Max,other.Max);
    	res.Gcd=gcd(Gcd,other.Gcd);
    	res.Xor=(Xor^other.Xor);
    	return res;
    }
};

struct SegTree {
	int n;
	vector<Info> info;
	SegTree(int n_) {
		n=n_;
		info.resize(n*4);
	}
	
	void Set(int v,int l,int r,int p,int val) {
		if (l == r) {info[v]=Info(val);return;}
		int m=l+r>>1;
		if (p <= m) Set(2*v,l,m,p,val);
		else Set(2*v+1,m+1,r,p,val);
		info[v]=info[v*2]+info[v*2+1];
	}
	
	Info query(int v,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return Info();
		if (ql <= l and r <= qr) return info[v];
		int m=l+r>>1;
		return query(2*v,l,m,ql,qr)+query(2*v+1,m+1,r,ql,qr);
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;
	n=1<<n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	SegTree st(n);
	for(int i=0;i<n;i++) st.Set(1,0,n-1,i,a[i]);
	
	while (q--) {
		int id,v;
		cin>>id>>v;
		id--;
		st.Set(1,0,n-1,id,v);
		int ans=0;
		int l=id,r=id;
		for(int i=1;i<=n;i<<=1) {
			int v1=st.query(1,0,n-1,l,r).Xor;
			if (id/i%2 == 0) {
				int v2=st.query(1,0,n-1,l+i,r+i).Xor;
				r+=i;
				if (v1 < v2) ans+=i;
			}
			else {
				int v2=st.query(1,0,n-1,l-i,r-i).Xor;
				l-=i;
				if (v1 <= v2) ans+=i;
			}
		}
		st.Set(1,0,n-1,id,a[id]);
		cout<<ans<<"\n";
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







