// Problem: 
//     P1080 [NOIP2012 提高组] 国王游戏
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1080
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//思路：左手/右手 为该大臣的贡献值，贡献值大的排后面
#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;



struct people{
	int left,right;
}peo[1005];
int a[1005],s[10001],slen,c[10001],ans[10001]={0},anslen=1;



bool cmp(people a1,people a2)
{
	return a1.left*a1.right<a2.left*a2.right;
}

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
	if (s[slen] == 0) slen--;
	slen++;
	return;
}
void div(int a1)
{
	int yushu=0;
	for(int i=slen-1;i>=0;i--){
		yushu=yushu*10+s[i];
		c[i]=yushu/a1;
		yushu%=a1;
	}
	return;
}
void prin()
{
	for(int i=anslen-1;i>=0;i--){		//去掉前导零
		if(ans[anslen-1]!=0 or anslen==1)break;
		anslen--;
	}
	for(int i=anslen-1;i>=0;i--) cout<<ans[i];
}

void comp()
{
	bool flag=0;
	for(int i=slen-1;i>=0;i--){		//去掉前导零
		if(s[slen-1]!=0 or slen==1)break;
		slen--;
	}
	for(int i=slen-1;i>=0;i--){
		if (ans[i]<c[i]){
			flag=1;
			break;
		}
	}
	if(flag){
		anslen=slen;
		for(int i=0;i<slen;i++) ans[i]=c[i];
	}
}

signed main()
{
	memset(s,0,10001);
	s[0]=1;
	slen=1;
	int n;
	cin>>n;
	rep(i,n+1) cin>>peo[i].left>>peo[i].right;
	sort(peo+1,peo+n+1,cmp);
	for(int i=0;i<n;i++){
		mul(peo[i].left);
		div(peo[i+1].right);
		comp();
	}
	prin();
	return 0;
}









