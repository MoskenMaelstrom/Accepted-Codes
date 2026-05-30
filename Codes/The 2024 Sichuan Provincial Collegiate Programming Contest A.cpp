// Problem: A. Reverse Pairs Coloring
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector<Info> tree;
	SegTree(int _) {
		n=_;
		tree.resize(n*4);
	}
	
	void Set(int p,int l,int r,int id,int val) {
		if (l == r) {tree[p]=Info(val);return;}
		int m=l+r>>1;
		if (id <= m) Set(2*p,l,m,id,val);
		else Set(2*p+1,m+1,r,id,val);
		tree[p]=tree[p*2]+tree[p*2+1];
	}
	
	Info query(int p,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return Info();
		if (ql <= l and r <= qr) return tree[p];
		int m=l+r>>1;
		return query(2*p,l,m,ql,qr)+query(2*p+1,m+1,r,ql,qr);
	}
	
	int kth(int p,int l,int r,int k) {
    	if (l == r) return l;
    	int m=l+r>>1;
    	int cnt=tree[2*p].sum;
		if (k <= cnt) return kth(2*p,l,m,k);
		else return kth(2*p+1,m+1,r,k-cnt);
	}
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	SegTree st(n+1);
	int lst=0;
	int ans=0;
	vector<bool> mark(n+2);
	for(int i=n;i>=1;i--) {
		int cur=st.query(1,1,n,1,a[i]).sum;
		if (!mark[a[i]-1]) st.Set(1,1,n,a[i],1);
		if (mark[a[i]+1]) st.Set(1,1,n,a[i]+1,0);
		mark[a[i]]=1;
		if (cur > lst) ans+=cur-lst;
		lst=cur;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







