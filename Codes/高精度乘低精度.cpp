#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


int s[10001],slen=1;
void mul(int a1)
{
	rep(i,slen) s[i]*=a1;
	rep(i,slen){
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	while (s[slen]>=10){
		s[slen+1]+=s[slen]/10;
		s[slen]%=10;
		slen++;
	}
	if (s[slen]==0) slen--;
	slen++;
}

signed main()
{
	memset(s,0,10001);
	s[0]=1;
	int a;
	cin>>a;
	mul(2);
	mul(3);
	mul(3);
	mul(4);
	for(int i=slen-1;i>=0;i--)cout<<s[i];
	return 0;
}