// Problem: U109897 [HDU5536]Chip Factory
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U109897
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e6*32;
int tree[N][2];
int pass[N];
int len=1;

void insert(int x) {
    int cur=0;
    pass[cur]++;
    for(int i=31;i>=0;i--) {
        int b=(x>>i)&1;
        if (tree[cur][b] == 0) {
            tree[len][0]=tree[len][1]=0;
            pass[len]=0;
            tree[cur][b]=len++;
        }
        cur=tree[cur][b];
        pass[cur]++;
    }
}

void erase(int x) {
    int cur=0;
    pass[cur]--;
    for (int i=31;i>=0;i--) {
        int b=(x>>i)&1;
        int nxt=tree[cur][b];
        pass[nxt]--;
        if (pass[nxt] == 0) tree[cur][b]=0;
        cur=nxt;
    }
}

int query(int x) {
    int cur=0;
    int ans=0;
    for(int i=31;i>=0;i--) {
        int b=(x>>i)&1;
        if (tree[cur][b^1] != 0) {
            ans|=(1<<i);
            cur=tree[cur][b^1];
        }
        else cur=tree[cur][b];
    }
    return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		insert(a[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++) {
		erase(a[i]);
		for(int j=i+1;j<n;j++) {
			erase(a[j]);
			ans=max(ans,query(a[i]+a[j]));
			insert(a[j]);
		}
		insert(a[i]);
	}
	cout<<ans;
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







