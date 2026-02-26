#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int a[N];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int l,r;
		cin>>l>>r;
		a[l]+=1;
		a[r+1]-=1;
	}
	int ans=0;
	for(int i=1;i<N;i++) {a[i]=a[i-1]+a[i]; ans=max(ans,a[i]);}
	cout<<ans;
	return 0;
}