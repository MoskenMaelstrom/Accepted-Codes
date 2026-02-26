// Problem: 
//     P2671 [NOIP2015 普及组] 求和
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2671
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

struct zu{
	int bian,num,col;
};
const int modn=1e4+7;
int ans=0;
zu a[100005];
vector<zu> b[100005];//开一个表,代表每个颜色带的编号
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].num;
	for(int i=1;i<=n;i++) cin>>a[i].col;
	for(int i=1;i<=n;i++) a[i].bian=i;
	for(int i=1;i<=n;i++) b[a[i].col].push_back(a[i]);
	
	for(int k=1;k<=m;k++)//遍历每个颜色
	{
		vector<zu> ji;//奇数组
		vector<zu> ou;//偶数组
		//先把颜色k的所有成员分奇偶
		for(int i=0;i<b[k].size();i++) {
			if (b[k][i].bian%2) ji.push_back(b[k][i]);
			else ou.push_back(b[k][i]);
		}
		
		//处理奇数组
		int sum1=0,sum2=0,sum3=0;
		for(int i=0;i<ji.size();i++) sum1=(sum1+ji[i].bian)%modn;
		for(int i=0;i<ji.size();i++) sum2=(sum2+ji[i].num)%modn;
		for(int i=0;i<ji.size();i++) sum3=(sum3+ji[i].bian * ji[i].num)%modn;
		if (ji.size() >= 2) ans=(ans+sum1*sum2+sum3*(ji.size()-2))%modn;
		//处理偶数组
		sum1=0,sum2=0,sum3=0;
		for(int i=0;i<ou.size();i++) sum1=(sum1+ou[i].bian)%modn;
		for(int i=0;i<ou.size();i++) sum2=(sum2+ou[i].num)%modn;
		for(int i=0;i<ou.size();i++) sum3=(sum3+ou[i].bian * ou[i].num)%modn;
		if (ou.size() >= 2) ans=(ans+sum1*sum2+sum3*(ou.size()-2))%modn;
		
	}
	cout<<ans;
	return 0;
}





