// Problem: F - Exactly K Steps 2
// Contest: AtCoder - AtCoder Beginner Contest 445
// URL: https://atcoder.jp/contests/abc445/tasks/abc445_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
vector<vector<int>> operator * (const vector<vector<int>>& A,const vector<vector<int>>& B) {
	const int n=A.size();
	vector C(n,vector<int>(n,inf));
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
        	if (A[i][k] == inf) continue;
            for (int j=0;j<n;j++) {
                C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    return C;
}

vector<vector<int>> Pow(vector<vector<int>> A,int exp) {
	int n=A.size();
	vector res(n,vector<int>(n,inf));
	for(int i=0;i<n;i++) res[i][i]=0;
	while (exp) {
		if (exp&1) res=res*A;
		A=A*A;
		exp>>=1;
	}
	return res;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector adj(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>adj[i][j];
		}
	}
	
	auto ans=Pow(adj,k);
	for(int i=0;i<n;i++) {
		cout<<ans[i][i]<<"\n";
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







