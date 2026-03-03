// Problem: P2709 【模板】莫队 / 小B的询问
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2709
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

struct Q {
    int l,r,id;
};

const int N=1e6;
vector<int> a;
vector<int> cnt(N+1);
vector<int> ans(N+1);
int sum=0;
void add(int x) {
	sum-=cnt[a[x]]*cnt[a[x]];
	cnt[a[x]]++;
	sum+=cnt[a[x]]*cnt[a[x]];
}

void del(int x) {
	sum-=cnt[a[x]]*cnt[a[x]];
	cnt[a[x]]--;
	sum+=cnt[a[x]]*cnt[a[x]];
}

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	a.resize(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<Q> que(m);
	for(int i=0;i<m;i++) {
		cin>>que[i].l>>que[i].r;
		que[i].id=i;
	}
	
    int B=max(1ll,(int)(n / sqrt(m)));
	sort(que.begin(),que.end(),[&](Q& a,Q& b) {
        if (a.l / B != b.l / B) return a.l < b.l;
        return ((a.l / B) & 1) ? a.r < b.r : a.r > b.r;
    });
	
    int l=1,r=0;
    vector<int> res(m);
    for (auto &q : que) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) del(l++);
        while (r > q.r) del(r--);
        res[q.id]=sum;
    }
    
    for(auto e1 : res) cout<<e1<<"\n";
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







