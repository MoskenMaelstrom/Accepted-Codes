#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,q,s[105];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	cin>>q;
	while(q--){
		cin>>k;//1e18
		int cnt=0;
		while(k>n){
			int t=0;
			while((1<<t)*n<k)t++;
			k-=(1<<(t-1))*n;
			cnt++;
		}
		if(cnt%2==1)cout<<(char)(s[k]-1+'a')<<endl;
		else cout<<s[k]<<endl;
	}
	return 0;
}