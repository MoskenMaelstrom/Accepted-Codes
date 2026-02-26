// Problem: F -  Adding Chords
// Contest: AtCoder - AtCoder Beginner Contest 424
// URL: https://atcoder.jp/contests/abc424/tasks/abc424_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int randINT(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void solve()
{
	int n,q;
	cin>>n>>q;
	SegTree st(n+1);
	while (q--) {
		int x,y;
		cin>>x>>y;
		x--,y--;	
		if (x > y) swap(x,y);
		else if (st.query(1,0,n,x,y).Xor == 0) {
			cout<<"Yes\n";
			int f=randINT(1,1e9);
			st.Set(1,0,n,x,st.query(1,0,n,x,x).Xor^f);
			st.Set(1,0,n,y,st.query(1,0,n,y,y).Xor^f);
		}
		else cout<<"No\n";
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









