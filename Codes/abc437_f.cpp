// Problem: F - Manhattan Christmas Tree 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Christmas (AtCoder Beginner Contest 437)
// URL: https://atcoder.jp/contests/abc437/tasks/abc437_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
	SegTree S(n);
	SegTree D(n);
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		S.Set(1,0,n-1,i,x+y);
		D.Set(1,0,n-1,i,x-y);
	}
	
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int id,x,y;
			cin>>id>>x>>y;
			id--;
			S.Set(1,0,n-1,id,x+y);
			D.Set(1,0,n-1,id,x-y);
		}
		else {
			int l,r,x,y;
			cin>>l>>r>>x>>y;
			l--,r--;
			int maxd=D.query(1,0,n-1,l,r).Max;
			int mind=D.query(1,0,n-1,l,r).Min;
			int maxs=S.query(1,0,n-1,l,r).Max;
			int mins=S.query(1,0,n-1,l,r).Min;
			int n1=max(abs(maxd-(x-y)), abs(mind-(x-y)));
			int n2=max(abs(maxs-(x+y)), abs(mins-(x+y)));
			cout<<max(n1,n2)<<"\n";
		}
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







