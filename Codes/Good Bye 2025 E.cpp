// Problem: E. Flatten or Concatenate
// Contest: Codeforces - Good Bye 2025
// URL: https://codeforces.com/problemset/problem/2178/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;


int query(int x,int y) {
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>x;
	return x;
}

void solve()
{
	int r;
	cin>>r;
	int l=1;
	int sum=query(l,r);
	while (l < r) {
		sum>>=1;
		int lo=l,hi=r,res=-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			int q=query(l,mid);
			if (q == sum) {res=mid;break;}
			else if (q < sum) lo=mid+1;
			else hi=mid-1;
		}
		if (res-l <= r-res-1) r=res;
		else l=res+1;
	}
	cout<<"! "<<sum<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







