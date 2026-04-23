#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
vector<vector<int>> operator * (const vector<vector<int>>& A,const vector<vector<int>>& B) {
	const int n=A.size();
	vector C(n,vector<int>(n,inf));
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
        	if (A[i][k] == inf) continue;
            for (int j=0;j<n;j++) {
            	if (B[k][j] == inf) continue;
                C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    return C;
}

vector<vector<int>> Pow(vector<vector<int>> E,vector<vector<int>> A,int exp) {
	int n=A.size();
	for(;exp;exp>>=1) {
		if (exp&1) E=E*A;
		A=A*A;
	}
	return E;
}

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n),d(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>d[i];
	
	vector<int> v1(m),v2(m);
	for(int i=0;i<m;i++) {
		int len;
		cin>>len;
		for(int j=0;j<len;j++) {
			int x;
			cin>>x;
			x--;
			v1[i]|=1<<x;
		}
		cin>>len;
		for(int j=0;j<len;j++) {
			int x;
			cin>>x;
			x--;
			v2[i]|=1<<x;
		}
	}
	
	vector A(1<<n,vector<int>(1<<n,inf));
	for(int s=0;s<1<<n;s++) {
		for(int i=0;i<m;i++) {
			int ns=s;
			ns|=v1[i];
			ns&=~v2[i];
			int cost=0;
			for(int b=0;b<n;b++) {
				if (((s>>b)&1) == 1 and ((ns>>b)&1) == 0) cost-=a[b];
				if (((s>>b)&1) == 0 and ((ns>>b)&1) == 1) cost+=d[b];
			}
			A[s][ns]=min(A[s][ns],cost);
		}
	}
	
	vector E(1<<n,vector<int>(1<<n,inf));
	for(int i=0;i<1<<n;i++) E[i][i]=0;
	auto res=Pow(E,A,k);
	int ans=inf;
	for(int i=0;i<1<<n;i++) {
		ans=min(ans,res[0][i]);
	}
	cout<<-ans<<"\n";
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







