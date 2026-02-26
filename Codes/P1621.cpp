// Problem: 
//     P1621 集合
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1621
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;

int f[MAXN];
bool mark[MAXN]={0};

int fin(int x)
{
	if (x != f[x]) f[x]=fin(f[x]);
	return f[x];
}

signed main()
{
	//欧拉筛
	int n=MAXN;	//<=n的质数
	vector<bool> pri(n+5,1);
	vector<int> realpri;
	
	for(int i=2;i <= n;i++){
		if (pri[i]) realpri.push_back(i);
		for(int j=0;j < realpri.size() and i*realpri[j] <= n;j++){
			pri[realpri[j]*i]=0;
			if (i%realpri[j] == 0) break;
		}
	}
	
	
	
	int a,b,p;
	cin>>a>>b>>p;
	for(int i=0;i<=b;i++) f[i]=i;	//并查集初始化
	p=lower_bound(realpri.begin(),realpri.end(),p)-realpri.begin();//把p更新成>=p的第一个质数的下标
	for(int i=p,num=realpri[i];num<=b;++i,num=realpri[i]) {//从p开始枚举质因数
		if (mark[num]) continue;	//如果这个数被枚举过了，那没必要再往上枚举了
		for(int j=1;j*num<=b;j++) {	//寻找j乘num
			if (j*num < a) continue;
			mark[j*num]=1;
			f[fin(j*num)]=fin(num);	//将j乘num的头并入num的头
		}
	}
	
	
	
	set<int> st;
	int ans=0;
	for(int i=a;i<=b;i++)
		if (st.find(fin(i)) == st.end()) {ans++;st.insert(fin(i));}
	cout<<ans<<endl;
	
	
	
	
	return 0;
}











