// Problem: H. Shiori Miyagi and Maximum Array Score
// Contest: Codeforces - Codeforces Round 1065 (Div. 3)
// URL: https://codeforces.com/contest/2171/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
struct Info {
	int sum,Max,Min,Gcd,Xor;
	Info() : sum(0),Max(0),Min(inf),Gcd(0),Xor(0) {};
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
	int n,m;
	cin>>n>>m;
	SegTree dp(m-n+1);
	auto calc=[&](int i,int a) {
		int res=0;
		while (a%i == 0) {
			a/=i;
			res++;
		}
		return res;
	};
	
	for(int i=2;i<=n;i++) {
		for(int j=(m-n)/i*i;j>=0;j-=i) {
			int a=i+j;
			int d=calc(i,a);
			dp.Set(1,0,m-n,j,dp.query(1,0,m-n,0,j).Max+d);
		}
	}
	
	cout<<dp.query(1,0,m-n,0,m-n+1).Max<<"\n";
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







