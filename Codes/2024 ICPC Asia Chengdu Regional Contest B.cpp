// Problem: B. Athlete Welcome Ceremony
// Contest: Codeforces - 2024 ICPC Asia Chengdu Regional Contest (The 3rd Universal Cup. Stage 15: Chengdu)
// URL: https://codeforces.com/gym/105486/problem/B
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
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

const int p=1e9+7;
int dp[301][301][301][3];
int pre[301][301];
void solve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	s=" "+s;
	
	int c1=ranges::count(s,'a');
	int c2=ranges::count(s,'b');
	int c3=ranges::count(s,'c');
	
	if (s[1] == 'a' or s[1] == '?') dp[1][1][0][0]=1;
	if (s[1] == 'b' or s[1] == '?') dp[1][0][1][1]=1;
	if (s[1] == 'c' or s[1] == '?') dp[1][0][0][2]=1;
	for(int i=2;i<=n;i++) {
		for(int x=0;x<=n;x++) {
			for(int y=0;y<=n;y++) {
				if (s[i] == 'a' or s[i] == '?') {
					dp[i][x+1][y][0]+=dp[i-1][x][y][1]+dp[i-1][x][y][2];
					dp[i][x+1][y][0]%=p;
				}
				if (s[i] == 'b' or s[i] == '?') {
					dp[i][x][y+1][1]+=dp[i-1][x][y][0]+dp[i-1][x][y][2];
					dp[i][x][y+1][1]%=p;
				}
				if (s[i] == 'c' or s[i] == '?') {
					dp[i][x][y][2]+=dp[i-1][x][y][0]+dp[i-1][x][y][1];
					dp[i][x][y][2]%=p;
				}
			}
		}
	}
	
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			for(int k=0;k<3;k++) pre[i][j]+=dp[n][i][j][k];
			if (j) pre[i][j]+=pre[i][j-1];
			pre[i][j]%=p;
		}
	}
	
	while (q--) {
		int a,b,c;
		cin>>a>>b>>c;
		a+=c1,b+=c2,c+=c3;
		a=min(a,n),b=min(b,n),c=min(c,n);
		int ans=0;
		for(int i=0;i<=a;i++) {
			 int l=max(0ll,n-i-c),r=b;
			 if (l > r) continue;
			 ans+=pre[i][r]-(l ? pre[i][l-1] : 0);
			 ans%=p;
		}
		cout<<(ans%p+p)%p<<"\n";
	}
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









