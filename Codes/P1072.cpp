// Problem: P1072 [NOIP 2009 提高组] Hankson 的趣味题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1072
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int a0,a1,b0,b1;
vector<int> realpri;
vector<array<int,2>> a;	//[0]存数值,[1]存数量
vector<int> b;//存的是b1的所有的因子

void shai()
{
	int n=100000;	//输入n,筛选出小于n的所有质数,时间复杂度为O(n)
	vector<bool> pri(n+5,1);
	
	for(int i=2;i <= n;i++){
		if (pri[i]) realpri.push_back(i);
		for(int j=0;j < realpri.size() and i*realpri[j] <= n;j++) {
			pri[realpri[j]*i]=0;
			if (i%realpri[j] == 0) break;
		}
	}
}

void dfs(int idx,int s)
{
	if (idx == a.size()) {b.push_back(s);return;}
	
	for(int i=0;i<=a[idx][1];i++) {
		dfs(idx+1,s);
		s*=a[idx][0];
	}
}

void solve()
{
	cin>>a0>>a1>>b0>>b1;
	a.clear();
	b.clear();
	int b11=b1;
	//分解质因子
	for(auto ele : realpri) {
		int cnt=0;
		while (b1%ele == 0) {
			cnt++;
			b1/=ele;
		}
		if (cnt != 0) a.push_back({ele,cnt});
	}
	if (b1 > 1) a.push_back({b1,1});
	
	
	dfs(0,1);//从0这个idx开始,当前总积是1
	int cnt=0;
	for(auto ele : b) {
		int x=ele;
		if (gcd(x,a0) == a1 and lcm(x,b0) == b11) cnt++;
	}
	cout<<cnt<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	shai();
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









