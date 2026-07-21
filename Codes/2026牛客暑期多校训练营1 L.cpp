// Problem: Substrings of Substrings
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133876/L
// Memory Limit: 2048 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct AC {
    static const int N=26;
    struct Node {
        int len,link,out,tag;
        array<int,N> nxt;
        Node() : len(0),link(0),out(0),tag(0),nxt{} {};
    };
    vector<Node> t;
    AC() {init();}
    
    void init() {
        t.assign(2,Node());
        t[0].nxt.fill(1);
        t[0].len=-1;
    }
    
    int newNode() {
        t.emplace_back();
        return t.size()-1;
    }
    
    int insert(string &a,int id=1) {
        int p=1;
        for (auto c : a) {
            int u=c-'a';
            if (next(p,u) == 0) {
                t[p].nxt[u]=newNode();
                t[next(p,u)].len=t[p].len+1;
            }
            p=next(p,u);
        }
        t[p].tag=id;
        return p;
    }
    
    void work() {
        queue<int> q;
        q.push(1);
        while (q.size()) {
            int x=q.front();
            q.pop();
            int f=link(x);
            t[x].out=t[f].tag ? f : t[f].out;
            for (int i=0;i<N;i++) {
                if (next(x,i) == 0) t[x].nxt[i]=next(link(x),i);
                else {
                    t[next(x,i)].link=next(link(x),i);
                    q.push(next(x,i));
                }
            }
        }
    }
    
    int next(int p,int x) {return t[p].nxt[x];}
    int link(int p) {return t[p].link;}
};

const int p=998244353;
const int inf=1e18;
void solve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> pre(n+1),pmn(n+1),smx(n+1);
	vector<int> ppre(n+1),suf(n+2);
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		pre[i]=pre[i-1]+x;
		pmn[i]=min(pmn[i-1],pre[i]);
		ppre[i]=(ppre[i-1]+pre[i])%p;
	}
	smx[n]=pre[n];
	for(int i=n-1;i>=1;i--) smx[i]=max(smx[i+1],pre[i]);
	for(int i=n;i>=1;i--) suf[i]=(suf[i+1]+pre[i])%p;
	
	AC ac;
	vector<int> bel(q+1);
	for(int i=1;i<=q;i++) {
		string ss;
		cin>>ss;
		bel[i]=ac.insert(ss);
	}
	ac.work();
	
	int siz=ac.t.size();
	vector<int> mx(siz,-inf);
	vector<int> sum(siz);
	vector<int> lst(siz);
	
	int u=1;
	for(int i=1;i<=n;i++) {
		u=ac.next(u,s[i]-'a');
		int v=ac.t[u].tag ? u : ac.t[u].out;
		while (v > 1) {
			int len=ac.t[v].len;
			mx[v]=max(mx[v],smx[i]-pmn[i-len]);
			int p0=lst[v] ? lst[v] : len-1;
			int x=(i-p0)*suf[i]%p;
            int sp=ppre[i-len]-(p0-len >= 0 ? ppre[p0-len] : 0);
            int y=(n-i+1)*sp%p;
            (sum[v]+=x-y)%=p;
            lst[v]=i;
            v=ac.t[v].out;
		}	
	}
	for(int i=1;i<=q;i++) {
		cout<<mx[bel[i]]<<" "<<(sum[bel[i]]+p)%p<<"\n";
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







