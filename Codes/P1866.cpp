// Problem: 
//     P1866 编号
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1866
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int modn=1e9+7;

int a[55];
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++) {
		a[i]-=i;
		ans*=a[i];
		ans%=modn;
	}
	cout<<ans;
	return 0;
}