// Problem: 
//     P1955 [NOI2015] 程序自动分析
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1955
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;


int f[400010];
struct bl{
	int a,b,opt;
};
int fin(int x)
{
	if (f[x] != x) f[x]=fin(f[x]);
	return f[x];
}

void solve()
{
	unordered_map<int,int> h;int p=1;//hash
	int n;
	cin>>n;
	rep(i,2*n) f[i]=i;	//初始化并查集与其反集
	vector<bl> arr(n+5);//存数据的
	
	rep(i,n) cin>>arr[i].a>>arr[i].b>>arr[i].opt;//把所有数据存入arr
	rep(i,n) {	
		if (h.find(arr[i].a) == h.end()) h[arr[i].a]=p++;//如果arr里没有，就映射一个
		if (h.find(arr[i].b) == h.end()) h[arr[i].b]=p++;
	}
	//所有arr里的元素都存入哈希表h中，不至于爆掉
	rep(i,n) if (arr[i].opt == 1) f[fin(h[arr[i].a])]=fin(h[arr[i].b]); //如果a和b应该相等,a并入b
	rep(i,n) {
		//退出条件
		if (arr[i].opt == 0 and fin(h[arr[i].a]) == fin(h[arr[i].b])) {cout<<"NO\n";return;}
	}
	cout<<"YES\n";
}

signed main()
{
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}



