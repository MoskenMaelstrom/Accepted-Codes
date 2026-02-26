// Problem: P4059 [Code+#1] 找爸爸
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4059
// Memory Limit: 500 MB
// Time Limit: 1000 ms
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

map<char,int> mp={{'A',0},{'T',1},{'G',2},{'C',3}};
int dp[3005][3005][3];
//dp[i][j][k]表示第一串匹配了i个,第二串匹配了j个,最后一次空格的状态(不加/第一个加/第二个加)  的值
void solve()
{	
	string s1,s2;
	cin>>s1>>s2;
	vector a(4,vector<int>(4));
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			cin>>a[i][j];
		}
	}
	int A,B;
	cin>>A>>B;
	int len1=s1.length();
	int len2=s2.length();
	//dp[0][0][0/1/2]=0;
	
	for(int i=1;i<3005;i++) {
		dp[i][0][0]=dp[0][i][0]=dp[i][0][1]=dp[0][i][2]=-IINF;
		dp[i][0][2]=dp[0][i][1]=-A-B*(i-1);
	}
	dp[0][0][1]=dp[0][0][2]=-IINF;
	
	auto add=[&](int x,int y) -> int {
		return (a[ mp[s1[x]] ][ mp[s2[y]] ]);
	};
		
	for(int i=1;i<=len1;i++) {
		for(int j=1;j<=len2;j++) {
			dp[i][j][0]=max( {dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j-1][2]} ) + add(i-1,j-1);
			dp[i][j][1]=max( {dp[i][j-1][0]-A,dp[i][j-1][1]-B,dp[i][j-1][2]-A} );
			dp[i][j][2]=max( {dp[i-1][j][0]-A,dp[i-1][j][1]-A,dp[i-1][j][2]-B} );
		}
	}
	
	
	cout<<max( {dp[len1][len2][0],dp[len1][len2][1],dp[len1][len2][2]} );
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









