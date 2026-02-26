// Problem: F - Beautiful Kadomatsu
// Contest: AtCoder - AtCoder Beginner Contest 439
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_f
// Memory Limit: 1024 MB
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

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	SegTree st(n+1);
	vector<int> L(n+1);
	for(int i=0;i<n;i++) {
		st.Set(1,0,n,a[i],st.query(1,0,n,a[i],a[i]).sum+1);
		L[i]=st.query(1,0,n,1,a[i]-1).sum;
	}
	
	int ans=0;
	int tmp=0;
	for(int i=0;i<n;i++) {
		int l=L[i];
		int r=a[i]-1-l;
		ans+=(tmp+l)*r;
		ans%=p;
		tmp+=tmp+l;
		tmp%=p;
	}
	cout<<ans;
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







