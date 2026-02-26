#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[10001],c[10001];//a为被除数，c为商
signed main()
{
	string A;
	int b,yushu=0,chead=0;
	cin>>A>>b;
	int lena=A.length();
	rep(i,lena) a[i]=A[i]-'0';
	rep(i,lena){
		c[i]=(yushu*10+a[i])/b;
		yushu=(yushu*10+a[i])%b;
	}
	while (c[chead] == 0 and chead<lena-1) chead++;
	for(int i=chead;i<lena;i++) cout<<c[i];
	return 0;
}