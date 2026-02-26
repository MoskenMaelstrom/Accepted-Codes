#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000100; //存的是所有节点的最大个数

int son[N][26], cnt[N], idx;
int depth[N]; // 用于存储每个节点离根节点的距离
int child_count[N];

void insert(const char str[]) {
    int p = 0;  // 每次从根节点开始找
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!son[p][u]) {
            son[p][u] = ++idx;
            depth[son[p][u]] = depth[p] + 1; // 记录新节点的深度
			child_count[p]++;
        }
        p = son[p][u];
    }
    cnt[p] ++; // 标记不是打在要插入的字符串的最后一个字母对应的节点的下一个节点上的***
}

int query(const char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int Fquery(const char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0; // 如果前缀不存在，直接返回0
        p = son[p][u];
    }
    
    // 从当前节点开始，统计所有子节点的 cnt 值
    int res = 0;
    queue<int> q;
    q.push(p);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        res += cnt[t]; // 累加当前节点的 cnt 值
        for (int i = 0; i < 26; i ++) {
            if (son[t][i]) {
                q.push(son[t][i]);
            }
        }
    }
    return res;
}


void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		insert(s.c_str());
	}
	int l,r;
	cin>>l>>r;
    
    int ans=0;
    for (int i = 1; i <= idx; i++) {
    	if (child_count[i] == 0) ans+=depth[i]*2;
    	else if (child_count[i] >= 2) ans-=depth[i]*2*(child_count[i]-1);
    }
    int maxd=0;
    for (int i = 1; i <= idx; i++) maxd=max(maxd,depth[i]);
    ans-=maxd;
    cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









