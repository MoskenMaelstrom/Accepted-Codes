// Problem: 
//     P1311 [NOIP2011 提高组] 选择客栈
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1311
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,k,p;
	cin>>n>>k>>p;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	vector<int> flag(n,0);
	for(int i=0;i<n;i++) if (b[i] <= p) flag[i]=1;
	
	int ans=0;//答案
	int t=-1;//t记录离r最近的(flag==1)的下标
	vector<int> cnt(50,0);//记录t位置即其之前的颜色i的数量
	for(int i=0;i<n;i++)
	{
		if (flag[i]) {	//更新t与cnt
			for(int j=t+1;j<=i;j++) cnt[a[j]]++;
			t=i;
			ans+=cnt[a[i]]-1;
		}
		else ans+=cnt[a[i]];
	}
	
	
	cout<<ans;
	return 0;
}


















