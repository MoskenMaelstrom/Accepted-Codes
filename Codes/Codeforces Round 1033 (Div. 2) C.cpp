// Problem: C. Divine Tree
// Contest: Codeforces - Codeforces Round 1033 (Div. 2) and CodeNite 2025
// URL: https://codeforces.com/problemset/problem/2120/C
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

void solve()
{
	int n,m;
	cin>>n>>m;
	
	int maxn=(n+1)*n/2;
	if (n > m or m > maxn) {cout<<"-1\n";return;}
	
	int k=n;
	int sum=0;
	while (k <= m-sum and k != -1) {
		sum+=k;
		k--;
	}
	k++;
	sum-=k;
	
	int rest=m-sum;
	vector<int> ans(n+1);
	for(int i=n;i>k;i--) {
		ans[i]=i;
	}
	
	for(int i=k;i>0;i--) {
		ans[i]=k-i+1;
	}
	for(int i=k-(rest-k);i<k;i++) {
		swap(ans[i],ans[i+1]);
	}
	
	cout<<ans[n]<<"\n";
	for(int i=n;i>1;i--) {
		cout<<ans[i]<<" "<<ans[i-1]<<"\n";
	}
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









