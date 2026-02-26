// Problem: D. For Wizards, the Exam Is Easy, but I Couldn't Handle It
// Contest: Codeforces - Codeforces Round 1006 (Div. 3)
// URL: https://codeforces.com/contest/2072/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &ele : a) cin>>ele;
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			cnt+=(a[i] > a[j]);//逆序对数量
		}
	}
	
	int ans=cnt;//最少的数量
	int l=0,r=0;
	for(int i=0;i<n;i++) {
		int cur=cnt;
		for(int j=i+1;j<n;j++) {
			cur+=(a[i] < a[j]);
			cur-=(a[i] > a[j]);
			if (cur < ans) {
				ans=cur,l=i,r=j;
			}
		}
	}
	cout<<l+1<<" "<<r+1<<endl;
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









