#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		rep(i,n){
			cout<<i*2+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}