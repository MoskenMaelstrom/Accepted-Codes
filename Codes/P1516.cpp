// Problem: P1516 青蛙的约会
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1516
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

//exgcd在gcd的基础上产生了一组特解
//Δx是d/b,Δy是d/a

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

void solve()
{
	int x,y,m,n,L;
	cin>>x>>y>>m>>n>>L;
	exgcd(m-n,L);
	if ((y-x)%d != 0) {cout<<"Impossible";return;}
	
	if (m-n > 0) {
		X*=(y-x)/d;
		int t=ceil((1.0-X)/(L/d));
		int minx=X+t*(L)/d;
		cout<<minx;
	} else {
		exgcd(n-m,L);
		X*=(x-y)/d;
		int t=ceil((1.0-X)/(L/d));
		int minx=X+t*(L)/d;
		cout<<minx;
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









