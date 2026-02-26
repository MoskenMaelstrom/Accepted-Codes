#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[10]={1,2,4,7,11,16,22,29,37,46};
void solve(){
	int n;
	cin>>n;
	cout<<"Yes"<<endl;
	for(int i=0;i<=n;i++){
		cout<<a[i]<<" ";
	}
	for(int i=n;i>0;i--){
		for(int j=a[i]+1;j<=a[i+1]-1;j++) cout<<j<<" ";
		for(int j=a[i]-1;j>a[i-1];j--) cout<<j<<" "<<j+i<<" ";
		cout<<a[i-1]<<" ";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}



