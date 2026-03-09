// Problem: I. Square Puzzle
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/I
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

string to[7];
unordered_map<string,int> vis;
void solve()
{
	string st=" ",ed=" ";
	for(int i=0;i<3;i++) {
		string s;
		cin>>s;
		st+=s;
	}
	for(int i=0;i<3;i++) {
		string s;
		cin>>s;
		ed+=s;
	}
	
	string ans=" ";
	
	for(int i=1;i<=9;i++) {
		for(int j=1;j<=9;j++) {
			if (ed[i] == st[j]) ans+=j+'0';
		}
	}
	
	if (vis[ans]) cout<<vis[ans]-1<<"\n";
	else cout<<"-1\n";
}

signed main()
{
	to[0]=" 312456789";
	to[1]=" 123645789";
	to[2]=" 123456978";
	to[3]=" 723156489";
	to[4]=" 183426759";
	to[5]=" 129453786";
	to[6]=" 741852963";
	string st=" 123456789";
	vis[st]=1;
	queue<pair<string,int>> q;
	q.push({st,1});
	while (!q.empty()) {
		auto [s,sum]=q.front();
		q.pop();
		for(int i=0;i<7;i++) {
			string cur=" ";
			for(int j=1;j<=9;j++) cur+=s[to[i][j]-'0'];
			if (vis[cur]) continue;
			q.push({cur,sum+1});
			vis[cur]=sum+1;
		}
	}
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







