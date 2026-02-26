// Problem: 
//     P4653 [CEOI2017] Sure Bet
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4653
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

double a[100005];
double b[100005];
bool cmp(double a1,double a2)//降序
{
	return a1>a2;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	
	double Ea=0,Eb=0,C=0;//初始化贡献值
	double ans=0;
	int p1=0,p2=0;
	while (p1 < n or p2 < n)
	{
		if (Ea < Eb and p1 != n or p2 == n)
		{
			C++;
			Ea+=a[++p1];
			ans=max( ans,min(Ea,Eb)-C );
		}
		else if (Ea > Eb and p2 != n or p1 == n)
		{
			C++;
			Eb+=b[++p2];
			ans=max( ans,min(Ea,Eb)-C );
		}
		else
		{
			if (a[p1+1] < 2 and b[p2+1] < 2) break;
			C+=2;
			Ea+=a[++p1];
			Eb+=b[++p2];
			ans=max(ans,min(Ea,Eb)-C);
		}
	}
	printf("%.4f",ans);
	return 0;
}






