// Problem: 
//     P2004 领地选择
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2004
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[1005][1005];
int a1[1005][1005];
int a2[1005][1005];
signed main()
{
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	
	for(int i=1;i<=n;i++) {
		int pos=1;
		int sum=0;
		for(int j=1;j<=c;j++) sum+=a[i][j];
		while (pos <= m-c+1) {
			a1[i][pos]=sum;
			sum-=a[i][pos];
			sum+=a[i][pos+c];
			pos++;
		}
	}
	
	for(int j=1;j<=m;j++) {
		int pos=1;
		int sum=0;
		for(int i=1;i<=c;i++) sum+=a1[i][j];
		while (pos <= n-c+1) {
			a2[pos][j]=sum;
			sum-=a1[pos][j];
			sum+=a1[pos+c][j];
			pos++;
		}
	}
	
	int maxn=-(1<<50);
	int ansx,ansy;
	for(int i=1;i<=n-c+1;i++) 
		for(int j=1;j<=m-c+1;j++) 
			if (maxn < a2[i][j]) maxn=a2[i][j],ansx=i,ansy=j;
	cout<<ansx<<" "<<ansy;
	return 0;
}







