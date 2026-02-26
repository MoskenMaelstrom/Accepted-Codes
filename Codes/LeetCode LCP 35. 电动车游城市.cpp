const int inf=0x3f3f3f3f;
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& a, int cnt, int start, int ed, vector<int>& b) {
		int n=b.size();
		vector vec(n,vector<int>(cnt+1,inf));
		vec[start][0]=0;
		vector adj(n,vector<array<int,2>>(0));
		for(int i=0;i<a.size();i++) {
			adj[a[i][0]].push_back({a[i][1],a[i][2]});
			adj[a[i][1]].push_back({a[i][0],a[i][2]});
		}
		
		set<array<int,3>> st;//{length, point, charge}
		st.insert({0,start,0});
		while (!st.empty()) {
			auto [len,u,c]=*st.begin();
			st.erase(st.begin());
			if (len > vec[u][c]) continue;
			if (u == ed) return len;
			if (c < cnt) {
				int cur=len+b[u];
				if (cur < vec[u][c+1]) {
					vec[u][c+1]=cur;
					st.insert({cur,u,c+1});
				}
			}
			
			for(auto [v,w] : adj[u]) {
				if (c >= w and len+w < vec[v][c-w]) {
					vec[v][c-w]=len+w;
					st.insert({len+w,v,c-w});
				}
			}
		}
		
		return -1;
    }
};



