// Problem: E - Count Sequences 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_e
// Memory Limit: 1024 MB
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

int p;
int C[5001][5001];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	int N=0;
	for(int i=0;i<n;i++) {cin>>a[i];N+=a[i];}
	int ans=1;
	for(int i=0;i<n;i++) {
		ans*=C[N][a[i]];
		ans%=p;
		N-=a[i];
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	cin>>p;
    for(int i = 0; i <= 5000; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % p;
        }
    }
	
	while (t--)
		solve();
	return 0;
}









