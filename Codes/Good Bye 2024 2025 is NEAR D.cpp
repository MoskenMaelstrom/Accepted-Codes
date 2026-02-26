// Problem: D. Refined Product Optimality
// Contest: Codeforces - Good Bye 2024: 2025 is NEAR
// URL: https://codeforces.com/problemset/problem/2053/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;
const int p=998244353;

int d,X,Y,PX,PY;//d为最大公因数; (X,Y)是一组特解
void exgcd(int a,int b)//a,b当前的两个过程数字,不用考虑入参大小
{
	if (b != 0) {
		exgcd(b,a%b);
		PX=X;//PX更新为下一次的x
		PY=Y;//PY更新为下一次的y
		X=PY;//求解的这次的x就是下次的y
		Y=PX-PY*(a/b);
	} else {
		d=a;
		X=1;
		Y=0;
	}
}
//n在p意义下的逆元
int niyuan(int n)
{
	exgcd(n,p);
	return (X%p+p)%p;
}


void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n),b(n);
	for(auto &e1 : a) cin>>e1;
	for(auto &e1 : b) cin>>e1;
	auto a1=a;
	auto b1=b;
	ranges::sort(a1);
	ranges::sort(b1);
	
	int ans=1;
	for(int i=0;i<n;i++) {
		ans*=min(a1[i],b1[i]);
		ans%=p;
	}
	cout<<ans<<" ";
	
	while (q--)
	{
		int o,x;
		cin>>o>>x;
		x--;
		if (o == 1) {
			int pos=upper_bound(a1.begin(),a1.end(),a[x]++)-a1.begin()-1;
			
			int inv=niyuan(min(a1[pos],b1[pos]));
			ans*=inv;
			ans%=p;
			ans*=min(++a1[pos],b1[pos]);
			ans%=p;
			cout<<ans<<" ";
		}
		else {
			int pos=upper_bound(b1.begin(),b1.end(),b[x]++)-b1.begin()-1;
			
			int inv=niyuan(min(a1[pos],b1[pos]));
			ans*=inv;
			ans%=p;
			ans*=min(a1[pos],++b1[pos]);
			ans%=p;
			cout<<ans<<" ";
		}
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









