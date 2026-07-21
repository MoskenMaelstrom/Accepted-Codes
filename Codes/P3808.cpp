// Problem: P3808 AC 自动机（简单版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3808
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
        t[p].tag++;
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

void solve()
{
	int n;
	cin>>n;
	AC ac;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		ac.insert(s);
	}
	ac.work();
	string s;
	cin>>s;
	int u=1,ans=0;
	for(auto c : s) {
		u=ac.next(u,c-'a');
		for(int v=u;v!=0 and ac.t[v].tag != -1;v=ac.t[v].out) {
			ans+=ac.t[v].tag;
			ac.t[v].tag=-1;
		}
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







