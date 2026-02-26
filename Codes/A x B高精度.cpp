#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[1001],b[1001],c[1001]={0};
signed main()
{
	string A,B;
	cin>>A>>B;
	int lena=A.length();
	int lenb=B.length();
	for(int i=lena-1,j=0;i>=0;i--,j++) a[j]=A[i]-'0';
	for(int i=lenb-1,j=0;i>=0;i--,j++) b[j]=B[i]-'0';
	for(int i=0;i<lena;i++)
		for(int j=0;j<lenb;j++){
			c[i+j]+=a[i]*b[j];
		}
	for(int i=0;i<lena+lenb;i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;	
	}
	while(lena+lenb != 0 and c[lena+lenb] == 0)lena--;
	for(int i=lena+lenb;i>=0;i--)cout<<c[i];
	return 0;
}