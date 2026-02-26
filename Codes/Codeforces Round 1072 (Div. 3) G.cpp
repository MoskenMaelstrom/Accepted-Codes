// Problem: G. Nastiness of Segments
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/G
// Memory Limit: 256 MB
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
	SegTree st(n);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		st.Set(1,0,n-1,i,num);
	}
	
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int id,x;
			cin>>id>>x;
			id--;
			st.Set(1,0,n-1,id,x);
		}
		else {
			int l,r;
			cin>>l>>r;
			l--,r--;
			int lo=l,hi=r,res=0;
			while (lo <= hi) {
				int mid=lo+hi>>1;
				int d=st.query(1,0,n-1,l,mid).Min-(mid-l);
				if (d == 0) {res=1;break;}	
				else if (d > 0) lo=mid+1; 
				else hi=mid-1;
			}
			
			if (res) cout<<"1\n";
			else cout<<"0\n";
		}
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







