// Problem: D. For the Champion
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e18;
const int D=1e9;
void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1];
	}
	
	vector<int> a1(n),a2(n),a3(n);
	for(int i=0;i<n;i++) {
		a1[i]=a[i][0]+a[i][1];
		a2[i]=-a[i][0]+a[i][1];
	}
	int maxn;
	int x1,y1,x2,y2,x3,y3;
	
	maxn=-inf;
	for(int i=0;i<n;i++) 
		if (maxn < a1[i]) maxn=a1[i],x1=a[i][0],y1=a[i][1];
		
	maxn=-inf;
	for(int i=0;i<n;i++) 
		if (maxn < a2[i]) maxn=a2[i],x2=a[i][0],y2=a[i][1];
		
	int res;
	int sum1,sum2;
	cout<<"? R 1000000000"<<endl;
	cin>>res;
	cout<<"? R 1000000000"<<endl;
	cin>>res;
	cout<<"? U 1000000000"<<endl;
	cin>>res;
	cout<<"? U 1000000000"<<endl;
	cin>>sum1;
	cout<<"? L 1000000000"<<endl;
	cin>>res;
	cout<<"? L 1000000000"<<endl;
	cin>>res;
	cout<<"? L 1000000000"<<endl;
	cin>>res;
	cout<<"? L 1000000000"<<endl;
	cin>>res;
	cout<<"? L 1000000000"<<endl;
	cin>>res;
	cout<<"? L 1000000000"<<endl;
	cin>>sum2;
	
	int d1=(sum1+sum2-(D*6-(x1-x2))+y1-y2)/2;
	
	int x=x2,y=y2;
	y+=d1;
	x-=(sum2-d1);
	x+=D*6;
	x-=D*2;
	y-=D*2;
	cout<<"! "<<x<<" "<<y<<endl;
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









