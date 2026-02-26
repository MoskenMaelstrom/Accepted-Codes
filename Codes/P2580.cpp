// Problem: P2580 于是他错误的点名开始了
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2580
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;


class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children; // 使用哈希表存储子节点
        int cnt;                                // 存储当前节点的计数
        int depth;                               // 存储当前节点的深度
        int child_count;                         // 存储当前节点的孩子数量

        TrieNode(int _depth) : cnt(0), depth(_depth), child_count(0) {}
    };

    TrieNode* root; // 根节点
    int idx;        // 当前节点的索引

public:
    Trie() : idx(0) {
        root = new TrieNode(0); // 初始化根节点
    }

    // 插入字符串
    void insert(const string& str) {
        TrieNode* p = root;  // 从根节点开始
        for (char ch : str) {
            if (p->children.find(ch) == p->children.end()) {
                // 如果子节点不存在，则动态扩展
                p->children[ch] = new TrieNode(p->depth + 1); // 添加新节点
                p->child_count++;                              // 父节点的孩子数量+1
            }
            p = p->children[ch]; // 移动到子节点
        }
        p->cnt++; // 在字符串的最后一个字符对应的节点上增加计数
    }

    // 查询字符串出现的次数
    int query(const string& str) {
        TrieNode* p = root;
        for (char ch : str) {
            if (p->children.find(ch) == p->children.end()) return 0; // 如果字符不存在，返回0
            p = p->children[ch];                                    // 移动到子节点
        }
        return p->cnt; // 返回字符串的计数
    }

    // 查询以str为前缀的所有字符串的出现次数
    int Fquery(const string& str) {
        TrieNode* p = root;
        for (char ch : str) {
            if (p->children.find(ch) == p->children.end()) return 0; // 如果前缀不存在，返回0
            p = p->children[ch];                                    // 移动到子节点
        }

        // 使用广度优先搜索（BFS）统计所有子节点的计数
        int res = 0;
        queue<TrieNode*> q;
        q.push(p);
        while (!q.empty()) {
            TrieNode* t = q.front();
            q.pop();
            res += t->cnt; // 累加当前节点的计数
            for (auto& child : t->children) {
                q.push(child.second); // 将子节点加入队列
            }
        }
        return res;
    }

    // 统计Trie树中的节点数量
    int count_nodes() {
        int res = 0;
        queue<TrieNode*> q;
        q.push(root); // 从根节点开始
        while (!q.empty()) {
            TrieNode* t = q.front();
            q.pop();
            res++; // 累加节点数量
            for (auto& child : t->children) {
                q.push(child.second); // 将子节点加入队列
            }
        }
        return res;
    }
};


void solve()
{
	Trie trie;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		trie.insert(s);
	}
	int m;
	cin>>m;
	set<string> st;
	for(int i=0;i<m;i++) {
		string s;
		cin>>s;
		if (st.find(s) != st.end()) cout<<"REPEAT\n";
		else if (trie.query(s) == 1) {cout<<"OK\n";st.insert(s);}
		else cout<<"WRONG\n";
	}
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









