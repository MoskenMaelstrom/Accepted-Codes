// Problem: B. Rectangles
// Contest: Codeforces - Codeforces Round 1058 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2159/B
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

vector<vector<int>> trans(const vector<vector<int>>& a) {
	int n=a.size();
	int m=a[0].size();
	vector b(m,vector<int>(n));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			b[i][j]=a[j][i];
		}
	}
	return b;
}

const int inf=1e18;
vector<vector<int>> get(const vector<vector<int>>& g) {
	int n=g.size();
	int m=g[0].size();
	
	if (n > m) {
		return trans(get(trans(g)));
	}
	
	vector L(n,vector<int>(n,-1));
	vector R(n,vector<int>(n,-1));
	
	vector ans(n,vector<int>(m,inf));
	for(int j=0;j<m;j++) {
		vector f(n,vector<int>(n,inf));
		for(int u=0;u<n;u++) {
			for(int d=u+1;d<n;d++) {
				int k=max(j+1,R[u][d]);
				while (k < m and (g[u][k] == 0 or g[d][k] == 0)) k++;
				R[u][d]=k;
				int len=inf;
				if (L[u][d] >= 0 and R[u][d] < m) len=R[u][d]-L[u][d]+1;
				if (g[u][j] == 1 and g[d][j] == 1 and L[u][d] >= 0) len=min(len,j-L[u][d]+1);
				if (g[u][j] == 1 and g[d][j] == 1 and R[u][d] < m) len=min(len,R[u][d]-j+1);
				
				if (len != inf) f[u][d]=(d-u+1)*len;
				if (g[u][j] == 1 and g[d][j] == 1) L[u][d]=j;
			}
		}
		
		for(int u=0;u<n;u++) {
			for(int d=n-1;d>u;d--) {
				f[u+1][d]=min(f[u+1][d],f[u][d]);
				f[u][d-1]=min(f[u][d-1],f[u][d]);
			}
		}
		
		for(int i=0;i<n;i++) {
			ans[i][j]=min(ans[i][j],f[i][i]);
		}
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (ans[i][j] == inf) ans[i][j]=0;
		}
	}
	return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector g(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char c;
			cin>>c;
			g[i][j]=c-'0';
		}
	}
	
	auto ans=get(g);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







