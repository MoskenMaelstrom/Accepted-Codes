// Problem: 
//     P1102 A-B 数对
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1102
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,c,pos1,pos2,ans=0;
	cin>>n>>c;
	vector<int> a(n+5);
	rep(i,n) cin>>a[i];
	sort(a.begin(),a.begin()+n);//升序
	for(int i=n-1,j=0;i>0;i--,j++){
		pos1=lower_bound(a.begin(),a.begin()+i,a[i]-c)-a.begin();//>=x左界
		pos2=upper_bound(a.begin(),a.begin()+i,a[i]-c)-a.begin();//>x 右界
		if (pos1 != n and a[pos1] == a[i]-c) ans+=pos2-pos1;
	}
	cout<<ans;
	return 0;
}