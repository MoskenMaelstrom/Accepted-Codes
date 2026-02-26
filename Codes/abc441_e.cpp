// Problem: E - A > B substring
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild Fes)
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_e
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
	string s;
	cin>>s;
	s=" "+s;
	vector<int> a(n+1);
	a[0]=n;
	for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i] == 'A')-(s[i] == 'B');
	
	SegTree st(2*n+1);
	st.Add(1,0,2*n,a[0],1);
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans+=st.query(1,0,2*n,0,a[i]-1).sum;
		st.Add(1,0,2*n,a[i],1);
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







