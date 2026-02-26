// Problem: P1253 扶苏的问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1253
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

vector<int> arr;
struct SegTree {
	vector<int> maxn,add,change,mark;
	
	SegTree() {}
	SegTree(int n) {
		maxn.assign(n,0);
		add.assign(n,0);
		change.assign(n,0);
		mark.assign(n,0);
	}
	
	void up(int i) {
		maxn[i]=max(maxn[i<<1],maxn[i<<1|1]);
	}
	
	void down(int i) {
		if (mark[i]) {
			Changelazy(i<<1,change[i]);
			Changelazy(i<<1|1,change[i]);
			mark[i]=0;
		}
		if (add[i] != 0) {
			Addlazy(i<<1,add[i]);
			Addlazy(i<<1|1,add[i]);
			add[i]=0;
		}
	}
	
	void Changelazy(int i,int v) {
		maxn[i]=v;
		add[i]=0;
		change[i]=v;
		mark[i]=1;
	}
	
	
	void Addlazy(int i,int v) {
		maxn[i]+=v;
		add[i]+=v;
	}
	void build(int l,int r,int i) {
		if (l == r) maxn[i]=arr[l];
		else {
			int mid=l+r>>1;
			build(l,mid,i<<1);
			build(mid+1,r,i<<1|1);
			up(i);
		}
	}
	
	
	void Change(int jl,int jr,int v,int l,int r,int i) {
		if (jl<=l and r <= jr) Changelazy(i,v);
		else {
			int mid=l+r>>1;
			down(i);
			if (jl <= mid) Change(jl,jr,v,l,mid,i<<1);
			if (mid+1 <= jr) Change(jl,jr,v,mid+1,r,i<<1|1);
			up(i); 
		}
	}
	void Add(int jl,int jr,int v,int l,int r,int i) {
		if (jl<=l and r <= jr) Addlazy(i,v);	
		else {
			int mid=l+r>>1;
			down(i);
			if (jl <= mid) Add(jl,jr,v,l,mid,i<<1);
			if (mid+1 <= jr) Add(jl,jr,v,mid+1,r,i<<1|1);
			up(i);
		}
	}
	
	
	int query(int jl,int jr,int l,int r,int i) {
		if (jl<=l and r <= jr) return maxn[i];
		int mid=l+r>>1;
		down(i);
		int ans=LLONG_MIN;
		if (jl <= mid) ans=max(ans,query(jl,jr,l,mid,i<<1));
		if (mid+1 <= jr) ans=max(ans,query(jl,jr,mid+1,r,i<<1|1));
		return ans;
	}
};


void solve()
{
	int n,q;
	cin>>n>>q;
	arr.assign(n+1,0);
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	SegTree seg(n<<2);
	seg.build(1,n,1);
	while (q--) {
		//o == 1区间重置
		//o == 2区间增加
		//o == 3查询
		int o,x,y,k;
		cin>>o>>x>>y;
		if (o == 2) {
			cin>>k;
			seg.Add(x,y,k,1,n,1);
		}
		if (o == 1) {
			cin>>k;
			seg.Change(x,y,k,1,n,1);
		}
		if (o == 3) {
			cout<<seg.query(x,y,1,n,1)<<endl;
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









