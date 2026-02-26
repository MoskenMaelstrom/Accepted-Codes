// Problem: I, Box
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108301/I
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

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
			x = f[x] = f[f[x]];
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

constexpr int dx[]={1,0,-1,0};
constexpr int dy[]={0,1,0,-1};
constexpr string str="DRUL";
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> box,target;
	vector wall(n,vector<bool>(m));
	
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<m;j++) {
			if (s[j] == '#') wall[i][j]=1;
			if (s[j] == '@' or s[j] == '!') box.push_back({i,j});
			if (s[j] == '*' or s[j] == '!') target.push_back({i,j});
		}
	}
	
	DSU dsu(n*m);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (wall[i][j] == 0) {
				if (i > 0 and wall[i-1][j] == 0) dsu.merge(i*m+j,(i-1)*m+j);
				if (j > 0 and wall[i][j-1] == 0) dsu.merge(i*m+j,i*m+j-1); 
			}
		}
	}
	
	ranges::sort(box,[&](auto a,auto b) {
		return dsu.find(a[0]*m+a[1]) < dsu.find(b[0]*m+b[1]);
	});
	
	ranges::sort(target,[&](auto a,auto b) {
		return dsu.find(a[0]*m+a[1]) < dsu.find(b[0]*m+b[1]);
	});
	
	int k=box.size();
	for(int i=0;i<k;i++) {
		auto [x1,y1]=box[i];
		auto [x2,y2]=target[i];
		if (!dsu.same(x1*m+y1,x2*m+y2)) {
			cout<<"-1\n";
			return;
		}
	}
	
	auto getpath = [&](auto s, auto t) {
		vector vis(n,vector<array<int,2>>(m,{-1,-1}));
	    vis[s[0]][s[1]]=s;
	     
	    queue<array<int, 2>> q;
	    q.push(s);
	    while (!q.empty()) {
	        auto [x,y]=q.front();
	        q.pop();
	         
	        for (int d=0;d<4;d++) {
	            int nx=x+dx[d];
	            int ny=y+dy[d];
	            if (0 <= nx and nx < n and 0 <= ny and ny < m and wall[nx][ny] == 0 and vis[nx][ny][0] == -1) {
	                vis[nx][ny]={x,y};
	                q.push({nx,ny});
	            }
	        }
	    }
	    vector<array<int, 2>> path;
	    while (t != s) {
	        path.push_back(t);
	        t=vis[t[0]][t[1]];
	    }
	    return path;	
	};
	
	vector<vector<array<int,2>>> path(k);
	for(int i=0;i<k;i++) path[i]=getpath(box[i],target[i]);
	
	vector<tuple<int,int,char>> ans;
	while (1) {
		int b=-1;
		for(int i=0;i<k;i++) {
			if (!path[i].empty() and (b == -1 or path[i].size() < path[b].size())) b=i;
		}
		if (b == -1) break;
		
		path[b]=getpath(box[b],target[b]);
		
		while (!path[b].empty()) {
			auto nxt=path[b].back();
			path[b].pop_back();
			int c=ranges::find(box,nxt)-box.begin();
			if (c < k) {
				swap(box[b],box[c]);
				path[c].push_back(box[b]);
				continue;
			}
			
			auto [x,y]=box[b];
			for(int d=0;d<4;d++) {
				int nx=x+dx[d];
				int ny=y+dy[d];
				if (nxt == array{nx,ny}) ans.push_back({x+1,y+1,str[d]});
			}
			box[b]=nxt;
		}
	}
	
	cout<<ans.size()<<"\n";
	for(auto [x,y,c] : ans) {
		cout<<x<<" "<<y<<" "<<c<<"\n";
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









