// Problem: B - Product Calculator
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 406）
// URL: https://atcoder.jp/contests/abc406/tasks/abc406_b
// Memory Limit: 1024 MB
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
using namespace std;

int count(int num) {
    if (num == 0) return 1;
    int cnt=0;
    while (num != 0) {
        num /= 10;
        cnt++;
    }
    return cnt;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int cur=1;
	for(int i=0;i<n;i++) {
		if (count(cur)+count(a[i])-1 > k or count(cur*a[i]) > k) cur=1;
		else cur*=a[i];
	}
	cout<<cur;
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









