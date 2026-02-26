// Problem: 
//     P2054 [AHOI2005] 洗牌
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2054
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;

int mul(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {  // 如果b的最低位是1
            result = result+a;
        }
        a <<= 1;  // a左移一位
        a%=(n+1);
        b >>= 1;  // b右移一位
    	result%=(n+1);
    }
    return result;
}

int x,y,px,py,d;
void exgcd(int a,int b)
{
	if (b == 0) {
		x=1;
		y=0;
		d=a;
	} else {
		exgcd(b,a%b);
		px=x;
		py=y;
		x=py;
		y=px-py*(a/b);
	}
}

int mi(int m)//计算2的m次方mod(n+1)
{
	int ans=1;
	int a=2;
	while (m != 0)
	{
		if (m&1) ans=mul(ans,a);
		a=mul(a,a);
		m>>=1;
	}
	return ans;
}

signed main()
{
	int m,l;
	cin>>n>>m>>l;
	if (m == 0) {cout<<l;return 0;}
	//x*(2^m) % (n+1)=l
	//x*(2^m) + y*(n+1) = l
	int a=mi(m),b=n+1;
	exgcd(a,b);
	x=(x%(n+1)+n+1)%(n+1);
	x=mul(l,x);
	cout<<x;
	return 0;
}







