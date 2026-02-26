// Problem: 
//     P1036 [NOIP2002 普及组] 选数
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1036
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,k,sum=0,ans=0,now=0;
vector<int> a;
bool is_prime(int num)
{
	if (num == 0 or num == 1) return 0;
	if (num == 2 or num == 3) return 1;
	if (num%2 == 0 or num%3 == 0) return 0;
	for(int i=5;i*i<=num;i+=6)
		if (num%i == 0 or num%(i+2) == 0) return 0;
	return 1;
}
void dfs(int x)
{
	if (x == n) return;
	//加上a[x]
	sum+=a[x];
	now++;
	if (now == k and is_prime(sum)) ans++;
	dfs(x+1);
	//不加a[x]
	sum-=a[x];
	now--;
	dfs(x+1);
}
signed main()
{
	cin>>n>>k;
	a.resize(n+5);
	rep(i,n) cin>>a[i];
	dfs(0);
	cout<<ans;
	return 0;
}










