// Problem: 智乃与模数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95335/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<array<int,3>> a;
	for(int l=1;l<=n;) {
		int v=n/l;
		int r=n/v;
		a.push_back({l,r,v});
		l=r+1;
	}
	
	//res是第k大的余数
	int anscnt=-1,anssum=-1;
	int lo=0,hi=n,res=-1,cnt,sum;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		
		cnt=0;
		sum=0;
		for(int d=a.size();d>=1;d--) {
			auto [l,r,v]=a[a.size()-d];
			int an=n-v*l;
			if (an < mid) continue;
			int x=(an-mid)/d+1;
			int a1=an-d*(x-1);
			
			cnt+=x;
			sum+=(a1+an)*x/2;
		}
		if (cnt < k) hi=mid-1;
		else lo=mid+1,res=mid,anscnt=cnt,anssum=sum;
	}
	
	cout<<sum-res*(cnt-k)<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









