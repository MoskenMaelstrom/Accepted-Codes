// Problem: 
//     P5266 【深基17.例6】学籍管理
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5266
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
map<string,int> mp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
	{
		int m,score;
		string name;
		cin>>m;
		if (m == 1){
			cin>>name>>score;
			mp[name]=score;
			cout<<"OK\n";
		}
		else if (m == 2){
			cin>>name;
			if (!mp[name]) cout<<"Not found\n";
			else cout<<mp[name]<<endl;
		}
		else if (m == 3){
			cin>>name;
			if (!mp[name]) cout<<"Not found\n";
			else {mp[name]=0;cout<<"Deleted successfully\n";}
		}
		else {
			int ans=0;
			for(auto i=mp.begin();i!=mp.end();i++){
				if (i->second > 0) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}











