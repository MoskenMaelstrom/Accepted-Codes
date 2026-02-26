// Problem: 
//     P1733 猜数（IO交互版）
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1733
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main() 
{
	int l=1,r=1000000000;
	while(l <= r) {
  	int res;
  	int mid=((l+r)>>1);
    cout<<mid<<endl;
    fflush(stdout);
    cin>>res;
    if (res == 0) return 0;
    else if (res == -1) l=mid+1;
    else if (res == 1) r=mid-1;
}
  return 0;
}