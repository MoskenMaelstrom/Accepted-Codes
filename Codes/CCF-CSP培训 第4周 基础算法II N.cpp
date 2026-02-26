// Problem: N - Connect 6
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/N
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

int dx[]={1,0,1,1};
int dy[]={0,1,1,-1};
void solve()
{
	int n;
	cin>>n;
	bool ok=0;
	vector a(n,vector<char>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<4;k++) {
				if (i+dx[k]*5 < 0 or i+dx[k]*5 >= n or j+dy[k]*5 < 0 or j+dy[k]*5 >= n) continue;
				int cnt=0;
				for(int l=0;l<6;l++) {
		            if (a[i+dx[k]*l][j+dy[k]*l] == '.') cnt++;
				}
				if (cnt <= 2) ok=1;
			}
		}
	}
	if (ok) cout<<"Yes";
	else cout<<"No";
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









