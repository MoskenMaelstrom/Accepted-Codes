#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[1001]={0},b[1001]={0},c[1001]={0};
signed main()
{
	string A,B;
	cin>>A>>B;
	for(int i=A.length()-1,j=0;i>=0;i--,j++)a[j]=A[i]-'0';
	for(int i=B.length()-1,j=0;i>=0;i--,j++)b[j]=B[i]-'0';
	int len=max(A.length(),B.length());
	rep(i,len){
		c[i]+=a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[len]==0)len--;
	for(int i=len;i>=0;i--)cout<<c[i];
	return 0;
}