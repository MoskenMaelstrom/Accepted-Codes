// Problem: K. Rainbow Subarray
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/K
// Memory Limit: 1024 MB
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
	int sum;
	Info() : sum(0) {};
    Info(int val) : sum(val) {};
    Info operator+(const Info &other) const {
    	Info res;
    	res.sum=sum+other.sum;
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
	
	int kth(int v,int l,int r,int k) {
    	if (l == r) return l;
    	int m=l+r>>1;
    	int cnt=info[2*v].sum;
		if (k <= cnt) return kth(2*v,l,m,k);
		else return kth(2*v+1,m+1,r,k-cnt);
	}
};

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]-=i;
		b[i]=a[i];
	}
	ranges::sort(b);
	b.erase(unique(b.begin(),b.end()),b.end());
	int m=b.size();
	SegTree st1(m);
	SegTree st2(m);
	
	auto work=[&](int len) -> int {
		if (len <= 1) return 0;
		int id=st1.kth(1,0,m-1,len+1>>1);
		int val=b[id];
		int lcnt=st1.query(1,0,m-1,0,id).sum;
		int lsum=st2.query(1,0,m-1,0,id).sum;
		int rcnt=st1.query(1,0,m-1,id+1,m-1).sum;
		int rsum=st2.query(1,0,m-1,id+1,m-1).sum;
		return lcnt*val-lsum+rsum-rcnt*val;
	};
	
	int ans=1,l=0;
	for(int r=0;r<n;r++) {
		int pos=ranges::lower_bound(b,a[r])-b.begin();
		st1.Add(1,0,m-1,pos,1);
		st2.Add(1,0,m-1,pos,a[r]);
		while (l < r and work(r-l+1) > k) {
			int p=lower_bound(b.begin(),b.end(),a[l])-b.begin();
			st1.Add(1,0,m-1,p,-1);
			st2.Add(1,0,m-1,p,-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
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







