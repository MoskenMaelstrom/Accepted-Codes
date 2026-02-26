#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
vector<int> a,b;
int sum;

//验证x时间之内所有的速度为2的球超过后面速度为0的球的数量是不是<=k
bool check(int x)
{
	sum=0;
	for(auto p : a) //遍历每个速度为2的球
		sum+=upper_bound(b.begin(),b.end(),x+p)-upper_bound(b.begin(),b.end(),p);
	return sum < k;
}

void solve()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		int p,v;
		cin>>p>>v;
		if (v == -1) v=0;
		if (v == 1) a.push_back(p);//a存速度为2的球
		else b.push_back(p);//b存速度为0的球
	}
	ranges::sort(a);
	ranges::sort(b);
	
	int l=1,r=1e18,ans;
	while (l <= r)
	{
		int mid=l+r>>1;
		if (check(mid)) l=mid+1;
		else ans=mid,r=mid-1;
		if (l > 1e12) {cout<<"No\n";return;}
	}
	double A=ans/2.0;
	printf("Yes\n%.10f",A);
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









