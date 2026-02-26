// Problem: P2613 【模板】有理数取余
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2613
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=19260817;
void Read(int &X)
{
    X = 0;
    char O = getchar();
    while (O < '0' || O > '9') O = getchar();
    while (O >= '0' && O <= '9')
    {
        X = ((X << 1) + (X << 3) + (O ^ 48)) % MOD;//输入有点大,特殊处理一下
        O = getchar();
    }
}

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
	int a,b;
	Read(a),Read(b);
	exgcd(b,MOD);
	X*=a/d;
	X=(X%MOD+MOD)%MOD;
	cout<<X;
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









