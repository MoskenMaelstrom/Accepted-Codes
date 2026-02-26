// Problem: P3807 【模板】卢卡斯定理/Lucas 定理
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3807
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

//题意:给定整数 n,m,p 的值,求出C(n+m,n)%p的值
int p;
vector<int> jc;




int d,X,Y,PX,PY;//d为最大公因数; (X,Y)是一组特解
void exgcd(int a,int b)//a,b当前的两个过程数字,不用考虑入参大小
{
	if (b != 0) {
		exgcd(b,a%b);
		PX=X;//PX更新为下一次的x
		PY=Y;//PY更新为下一次的y
		X=PY;//求解的这次的x就是下次的y
		Y=PX-PY*(a/b);
	} else {
		d=a;
		X=1;
		Y=0;
	}
}
//n在p意义下的逆元
int niyuan(int n)
{
	exgcd(n,p);
	return (X%p+p)%p;
}



int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*niyuan(jc[m-n])%p*niyuan(jc[n])%p;
}

int Lucas(int m,int n)
{
	if (m == 0) return 1;
	return C(m%p,n%p)*Lucas(m/p,n/p)%p;
}
void solve()
{
	
	int n,m;
	cin>>n>>m>>p;
	//提前处理一下阶乘
	jc.assign(p+1,1);
	for(int i=2;i<=p;i++) jc[i]=jc[i-1]*i%p;
	
	cout<<Lucas(n+m,n)<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









