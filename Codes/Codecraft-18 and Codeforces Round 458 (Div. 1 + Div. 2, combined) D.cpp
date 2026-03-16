// Problem: D. Bash and a Tough Math Puzzle
// Contest: Codeforces - Codecraft-18 and Codeforces Round 458 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/914/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
    	// res.sum=sum+other.sum;
    	// res.Min=min(Min,other.Min);
    	// res.Max=max(Max,other.Max);
    	res.Gcd=gcd(Gcd,other.Gcd);
    	// res.Xor=(Xor^other.Xor);
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
	
	void Q(int v,int l,int r,int ql,int qr,int x,int& cnt) {
		if (cnt > 1) return;
		if (ql > r or qr < l) return;
		if (ql <= l and r <= qr) {
			if (info[v].Gcd%x == 0) return;
			if (l == r or cnt > 0) {cnt++;return;}
		}
		int m=l+r>>1;
		Q(2*v,l,m,ql,qr,x,cnt);
		Q(2*v+1,m+1,r,ql,qr,x,cnt);
	}
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	SegTree st(n);
	for(int i=0;i<n;i++) st.Set(1,0,n-1,i,a[i]);
	int q;
	cin>>q;
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int cnt=0;
			int l,r,x;
			cin>>l>>r>>x;
			l--,r--;
			st.Q(1,0,n-1,l,r,x,cnt);
			if (cnt <= 1) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else {
			int id,y;
			cin>>id>>y;
			id--;
			st.Set(1,0,n-1,id,y);
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







