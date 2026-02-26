// Problem: B. Blood Memories
// Contest: Codeforces - The 2025 ICPC Asia Chengdu Regional Contest (The 4rd Universal Cup. Stage 4: Grand Prix of Chengdu)
// URL: https://codeforces.com/gym/106161/problem/B
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
vector<vector<int>> operator * (const vector<vector<int>>& A,const vector<vector<int>>& B) {
	const int n=A.size();
	vector C(n,vector<int>(n,-inf));
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
        	if (A[i][k] == -inf) continue;
            for (int j=0;j<n;j++) {
                C[i][j]=max(C[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    return C;
}

void solve()
{
	int n,m,k,r;
	cin>>n>>m>>k>>r;
	vector<int> a(n),cost(n);
	for(int i=0;i<n;i++) {
		cin>>a[i]>>cost[i];
	}
	
	vector A(1<<n,vector<int>(1<<n));
	for(int i=0;i<1<<n;i++) {
		for(int j=0;j<1<<n;j++) {
			int suma=0,sumc=0;
			for(int b=0;b<n;b++) {
				if ((j>>b)&1) {
					suma+=a[b];
					if ((i>>b)&1) sumc+=cost[b]+k; 
					else sumc+=cost[b];
				}
			}
			if (sumc <= m) A[i][j]=suma;
		}
	}
	vector E(1<<n,vector<int>(1<<n));
	for(;r;r>>=1) {
		if (r&1) E=E*A;
		A=A*A; 
	}
	int ans=0;
	for(int i=0;i<1<<n;i++) {
		for(int j=0;j<1<<n;j++) {
			ans=max(ans,E[i][j]);
		}
	}
	cout<<ans<<"\n";
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







