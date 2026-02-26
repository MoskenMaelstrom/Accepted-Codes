// Problem: 
//     P2661 [NOIP2015 提高组] 信息传递
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2661
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;

int a[MAXN];//记录图
int b[MAXN];//记录深度
bool mark[MAXN];//查重
int ans=MAXN;
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		if (mark[i]) continue;//如果走过，跳过
		else {
			int deep=1;
			int pos=i;
			bool flag=0;//判断要不要运算
			memset(b,0,sizeof(b));
			while (1) {
				mark[pos]=1;
				b[pos]=deep++;
				pos=a[pos];//走一步
				if (mark[pos] == 1 and b[pos] == 0) break;
				if (mark[pos] == 1 and b[pos] != 0) {flag=1;break;}
			}
			if (flag) ans=min(ans,deep-b[pos]);
		}
	}
	cout<<ans;
	return 0;
}




