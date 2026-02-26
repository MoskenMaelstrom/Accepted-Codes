#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+5);
	rep(i,n) {cin>>a[i];a[i]=pow(a[i],2);}
	int maxsum=0;
	rep(i,n) maxsum+=a[i];
	int q=0,p=maxsum,ansmid,mid,now,sum;
	rep(i,n) q=max(q,a[i]);//初始化q,p
	
	while (q<=p)
	{
		now=0;
		sum=1;
		mid=(q+p)/2;
		rep(i,n){
			if (now+a[i] <= mid) now+=a[i];
			else {
				sum++;
				now=a[i];
			}
		}
		if (sum<=k) {	//合法，减小mid
			ansmid=mid;
			p=mid-1;
		}
		else q=mid+1;
	}
	cout<<ansmid;
	return 0;
}







