// Problem: P2085 最小函数值
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2085
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10001;

void solve()
{
	
    int n,m,i,j,cmin,jmin;
    cin>>n>>m;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> F(N);
    for(i=0;i<n;i++) {
        cin>>A[i]>>B[i]>>C[i];
        F[i]=1;
    }
    for(i=0;i<m;i++) {
        cmin=10000000;
        for(j=0;j<n;j++)
        {
            if(A[j]*F[j]*F[j]+B[j]*F[j]+C[j]<cmin) cmin=A[j]*F[j]*F[j]+B[j]*F[j]+C[j],jmin=j;
        }
        cout<<A[jmin]*F[jmin]*F[jmin]+B[jmin]*F[jmin]+C[jmin]<<" ";
        F[jmin]++;
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
