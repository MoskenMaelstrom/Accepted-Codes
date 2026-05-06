// Problem: F. It Just Keeps Going Sideways
// Contest: Codeforces - Codeforces Round 1096 (Div. 3)
// URL: https://codeforces.com/contest/2227/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
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
	
	void Add(int v,int l,int r,int p,int val) {
		if (l == r) {info[v]=info[v]+Info(val);return;}
		int m=l+r>>1;
		if (p <= m) Add(2*v,l,m,p,val);
		else Add(2*v+1,m+1,r,p,val);
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	SegTree st1(n+1),st2(n+1);
	vector<int> vec(n);
	int ans=0;
	for(int i=n-1;i>=0;i--) {
		int cnt=st1.query(1,0,n,0,a[i]).sum;
		int d=st2.query(1,0,n,0,a[i]).sum;
		vec[i]=cnt;
		ans+=cnt*a[i]-d;
		st1.Add(1,0,n,a[i],1);
		st2.Add(1,0,n,a[i],a[i]);
	}
	
	// cout<<ans<<"\n";
	int maxd=0;
	SegTree st0(n+1);
	for(int i=0;i<n;i++) {
		maxd=max(maxd,st0.query(1,0,n,a[i],n).sum-vec[i]);
		st0.Add(1,0,n,a[i],1);
	}
	ans=max(ans,ans+maxd);
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







