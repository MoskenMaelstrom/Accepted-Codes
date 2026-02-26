class Solution {
public:
    int shortestPathAllKeys(vector<string>& a) {
    	int dx[4]={1,-1,0,0};
    	int dy[4]={0,0,1,-1};
        int n=a.size();
        int m=a[0].size();
        int sx=0,sy=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (a[i][j] == '@') {
                    sx=i;
                    sy=j;
                }
                else if (islower(a[i][j])) {
                    if (!mp.contains(a[i][j])) {
                    	int idx=mp.size();
                    	mp[a[i][j]]=idx;
                    }
                }
            }
        }
        
        queue<array<int,3>> q;
        vector vec(n,vector<vector<int>>(m,vector<int>(1<<mp.size(),-1)));
        q.push({sx,sy,0});
        vec[sx][sy][0]=0;
        while (!q.empty()) {
        	auto [x,y,mask]=q.front();
        	q.pop();
        	for(int i=0;i<4;i++) {
        		int nx=x+dx[i];
        		int ny=y+dy[i];
        		if (nx<0 or nx>=n or ny<0 or ny>=m or a[nx][ny]=='#' or vec[nx][ny][mask]!=-1) continue;
        		if (a[nx][ny] == '.' or a[nx][ny] == '@') {
        			vec[nx][ny][mask]=vec[x][y][mask]+1;
     			  	q.push({nx,ny,mask});
        		}
        		else if (islower(a[nx][ny])) {
        			int idx=mp[a[nx][ny]];
        			int cur=mask|1<<idx;
        			vec[nx][ny][cur]=vec[x][y][mask]+1;
        			if (cur == (1<<mp.size())-1) return vec[nx][ny][cur];
     			  	q.push({nx,ny,cur});
        		}
        		else {
        			int idx=mp[tolower(a[nx][ny])];
        			if (mask>>idx&1) {
        				vec[nx][ny][mask]=vec[x][y][mask]+1;
     			  		q.push({nx,ny,mask});	
        			}
        		}
        	}
        }
    	return -1;
    }
};




