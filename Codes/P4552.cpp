// Problem: 
//     P4552 [Poetize6] IncDec Sequence
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4552
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int a[N],b[N];
signed main()
{
	int n;
	cin>>n;
	set<int> st;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		st.insert(a[i]);
	}
	int a1=0,a2=0,ans;
	for(int i=2;i<=n;i++) {
		b[i]=a[i]-a[i-1];
		if (b[i] < 0) a1-=b[i];
		if (b[i] > 0) a2+=b[i];
	}	
	ans=min(a1,a2)+abs(a1-a2);
	cout<<ans<<endl<<abs(a1-a2)+1;
	
	return 0;
}



















