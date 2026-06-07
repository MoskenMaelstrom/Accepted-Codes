// Problem: U109923 [Codechef REBXOR]Nikitosh and xor
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U109923
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=4e5*32;
int tree[N][2];
int pass[N];
int len=1;

void insert(int x) {
    int cur=0;
    pass[cur]++;
    for(int i=30;i>=0;i--) {
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
    for (int i=30;i>=0;i--) {
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
    for(int i=30;i>=0;i--) {
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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> L(n+2);
	insert(0);
	int x=0;
	for(int i=1;i<=n;i++) {
		x^=a[i];
		L[i]=max(L[i-1],query(x));
		insert(x);
	}
	
	for(int i=0;i<len;i++) {
		pass[i]=0;
		tree[i][0]=0;
		tree[i][1]=0;
	}
	len=1;
	
	x=0;
	vector<int> R(n+2);
	insert(0);
	for(int i=n;i>=1;i--) {
		x^=a[i];
		R[i]=max(R[i+1],query(x));
		insert(x);
	}
	
	int ans=0;
	for(int i=1;i<=n-1;i++) {
		ans=max(ans,L[i]+R[i+1]);
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







