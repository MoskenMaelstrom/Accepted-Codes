// Problem: G. Function Query
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/G
// Memory Limit: 256 MB
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
const int N=4e5*32;
int tree[N][2];
int ans[N];
int len=1;

void insert(int x,int id) {
    int cur=0;
    for(int i=30;i>=0;i--) {
        int b=(x>>i)&1;
        if (tree[cur][b] == 0) {
            tree[len][0]=tree[len][1]=0;
            ans[len]=inf;
            tree[cur][b]=len++;
        }
        cur=tree[cur][b];
        ans[cur]=min(ans[cur],id);
    }
}

int query(int x,int y) {
    int cur=0;
    int lo=1e18,hi=1e18;
    for(int i=30;i>=0;i--) {
    	int xb=(x>>i)&1;
    	int yb=(y>>i)&1;
    	if (yb == 0) hi=min(hi,ans[tree[cur][xb^1]]);
    	else lo=min(lo,ans[tree[cur][xb]]);
    	cur=tree[cur][xb^yb];
    	if (cur == 0) break;
    }
    
    if (cur != 0) {
    	if (ans[cur] == 0) return ans[cur]-1;
    	else return ans[cur];
    }
    else if (lo != 1 and lo != inf) return lo-1;
    else if (hi != 1 and hi != inf) return hi-1;
    else return -1;
}

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	fill(ans,ans+N,inf);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		insert(a[i],i);
	}
	
	while (q--) {
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<"\n";
	}
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







