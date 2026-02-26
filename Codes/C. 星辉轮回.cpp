#include<bits/stdc++.h>
using namespace std;
const int MAX=20001;
int a[MAX];	//a[i]代表1~i求和

int gcd(int a1,int a2)	//最大公因数(辗转相除法)
{
	if (a1>a2) swap(a1,a2);
	return a1 ? gcd(a2%a1,a1) : a2;
}
int lcm(int a1,int a2)	//最小公倍数
{
	return a1*a2/gcd(a1,a2);
}

void solve()
{
	int N,Sn,b,t,k;
	cin>>N;
	k=upper_bound(a,a+MAX,N)-a;		//k是n+1
	Sn=a[k-1];
	if (Sn == N) {cout<<1<<endl;return;}
	b=N-Sn;
	t=lcm(b,k)/b;
	cout<<t<<endl;
}

signed main()
{
	a[0]=0;
	for(int i=1;i<MAX;i++) a[i]=a[i-1]+i;
	
	int t;
	cin>>t;
	while (t--) solve();
	
	return 0;
}




