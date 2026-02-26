#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	ranges::sort(a);
	
	int sum=0;
	for(int i=0;i<n;i++) sum+=a[i][1];
	
	int pos=0;
	int cnt=0;
	for(int i=0;i<n;i++) {
		cnt+=a[i][1];
		if (cnt > sum/2) {pos=i;break;}
	}
	
	int sum1=0,sum2=0;
	int ans1=0,ans2=0;
	for(int i=0;i<pos;i++) {
		sum1+=a[i][1];
		ans1+=a[i][0]*a[i][1];
	}
	for(int i=pos+1;i<n;i++) {
		sum2+=a[i][1];
		ans2+=a[i][0]*a[i][1];
	}
	
	ans2+=a[pos][0]*(sum1-sum2);
	cout<<ans2-ans1<<endl;
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









