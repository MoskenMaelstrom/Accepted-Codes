// Problem: 
//     P1403 [AHOI2005] 约数研究
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1403
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) ans+=n/i;
    cout<<ans;
}