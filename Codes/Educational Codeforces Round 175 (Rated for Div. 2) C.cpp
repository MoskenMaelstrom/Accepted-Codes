// Problem: C. Limited Repainting
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
string s;
vector<int> a;

bool check(int num)
{
	vector<array<int,2>> arr;
	int cnt=0;//记录赦免的个数
	for(int i=0;i<n;i++) {
		if (a[i] > num) {
			if (s[i] == 'B') arr.push_back({1,a[i]});
			else arr.push_back({2,a[i]});
		}
	}
	if (arr.size() == 0) return 1;
	if (arr[0][0] == 1) cnt++;
	for(int i=1;i<arr.size();i++) {
		if (arr[i-1][0] == 2 and arr[i][0] == 1) cnt++;
	}
	if (cnt <= k) return 1;
	else return 0;
}

void solve()
{
	cin>>n>>k;
	cin>>s;
	a.assign(n,0);
	for(auto &ele : a) cin>>ele;
	
	int l=0,r=1e10,ans=0;
	while (l <= r)
	{
		int mid=l+r>>1;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	ranges::sort(a);
	if (ans == 0) cout<<0<<endl;
	else cout<<*lower_bound(a.begin(),a.end(),ans)<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









