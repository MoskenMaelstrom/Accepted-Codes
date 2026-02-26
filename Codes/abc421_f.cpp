// Problem: F - Erase between X and Y
// Contest: AtCoder - AtCoder Beginner Contest 421
// URL: https://atcoder.jp/contests/abc421/tasks/abc421_f
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

void solve()
{
	int q;
	cin>>q;
	
	unordered_map<int,int> nxt;
	nxt[0]=-1;
	for(int i=1;i<=q;i++) {
		int o;
		cin>>o;
		if (o == 1) {
			int cur;
			cin>>cur;
			nxt[i]=nxt[cur];
			nxt[cur]=i;
		}
		else {
			int x,y;
			cin>>x>>y;
			int sum1=0,sum2=0;
			int st1=x,st2=y;
			while (st1 != y and st2 != x and st1 != -1 and st2 != -1) {
				st1=nxt[st1];
				st2=nxt[st2];
				if (st1 == y or st2 == x or st1 == -1 or st2 == -1) break;
				sum1+=st1;
				sum2+=st2;
			}
			if (st1 == y) {cout<<sum1<<"\n";nxt[x]=y;}
			else if (st2 == x) {cout<<sum2<<"\n";nxt[y]=x;}
			else if (st1 == -1) {
				sum2+=st2;
				while (st2 != x) {
					st2=nxt[st2];
					if (st2 == x) break;
					sum2+=st2;
				}
				cout<<sum2<<"\n";
				nxt[y]=x;
			}
			else if (st2 == -1) {
				sum1+=st1;
				while (st1 != y) {
					st1=nxt[st1];
					if (st1 == y) break;
					sum1+=st1;
				}
				cout<<sum1<<"\n";
				nxt[x]=y;
			}
		}
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









