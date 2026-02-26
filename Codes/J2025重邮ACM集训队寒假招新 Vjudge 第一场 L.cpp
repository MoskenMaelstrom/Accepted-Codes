#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> T;
struct DSU {
	vector<int> f,siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];//路径压缩，使树扁平
		}
		return x;
	}
	
	bool same(int x,int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (x == y) return 0;
		siz[x] += siz[y];
		f[y]=x;
		T[x]=min(T[x],T[y]);///由于y归属于x,所以x要保存的是整个集合里最小的时间
		return 1;
	}
	
	int elesize(int x) {
		return siz[find(x)];
	}
	
	//返回根的数量
	int count() {
		unordered_set<int> roots;
		for(int i=0;i<f.size();i++) roots.insert(find(i));
		return roots.size();
	}
};

struct dian {
	int x,y,t,num;
};

bool cmpx(dian a1,dian a2)
{
	if (a1.x == a2.x) return a1.y < a2.y;
	else return a1.x < a2.x;
}

bool cmpy(dian a1,dian a2)
{
	if (a1.y == a2.y) return a1.x < a2.x;
	else return a1.y < a2.y;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	T.resize(n);//每个点都有自己的爆炸时间
	DSU D(n);
	vector<dian> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i].x>>a[i].y>>a[i].t;
		a[i].num=i;
		T[i]=a[i].t;//初始化爆炸时间
	}
	
	
	ranges::sort(a,cmpx);//先排x再排y
	for(int i=0;i<n-1;i++)
		if (a[i].x == a[i+1].x and a[i+1].y-a[i].y <= k) D.merge(a[i].num,a[i+1].num);
 		
	ranges::sort(a,cmpy);//先排y再排x
	for(int i=0;i<n-1;i++)
		if (a[i].y == a[i+1].y and a[i+1].x-a[i].x <= k) D.merge(a[i].num,a[i+1].num);
	
	vector<int> ans;
	for(int i=0;i<n;i++) if (D.find(a[i].num) == a[i].num) ans.push_back(T[a[i].num]);
	ranges::sort(ans);
	ranges::reverse(ans);
	int m=ans.size();
	int c=0;
	//从第一秒开始模拟
	for(int i=1;i<m;i++) {
		if (ans[i] == i) {c=i;break;}
		else if (ans[i] < i) {c=i-1;break;}
		c=i;
	}
	cout<<c<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









