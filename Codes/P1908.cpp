// Problem: 
//     P1908 逆序对
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1908
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;

int b[N];//一个桶的树状数组
int n;

int lowbit(int x) {return x&(-x);}

void add(int x,int k)//x位置加上一个1
{
	for(int i=x;i<=n;i+=lowbit(i)) b[i]+=k;
}
int sum(int x)//求x位置的前缀和
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=b[i];
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<int> arr=a;
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	for(int i=1;i<=n;i++) a[i]=upper_bound(arr.begin(),arr.end(),a[i])-arr.begin();
	//边查边维护树状数组b
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans+=i-sum(a[i])-1;
		add(a[i],1);
	}
	cout<<ans;
	return 0;
}












