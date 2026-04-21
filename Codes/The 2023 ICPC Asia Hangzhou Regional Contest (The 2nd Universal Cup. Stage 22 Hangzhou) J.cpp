// Problem: J. Mysterious Tree
// Contest: Codeforces - The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)
// URL: https://codeforces.com/gym/104976/problem/J
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int query(int u,int v) {
	cout<<"? "<<u<<" "<<v<<endl;
	int res;
	cin>>res;
	return res;
}

void solve()
{
	int n;
	cin>>n;
	bool ok=0;
	if (n&1) {
		for(int i=1;i<=n;i+=2) {
			if (i == n) i--;
			int res=query(i,i+1);
			if (res == 1) {
				int i1;
				int r;
				for(int j=1;j<=n;j++) {
					if (j != i and j != i+1) {
						i1=j;
						r=query(i,j);
						break;
					}
				}
				
				if (r == 0) {
					int i2;
					for(int j=1;j<=n;j++) {
						if (j != i and j != i+1) {
							i2=j;
							r=query(i+1,j);
							break;
						}
					}
					if (r == 0) cout<<"! 1"<<endl;
					else {
						for(int j=1;j<=n;j++) {
							if (j != i and j != i+1 and j != i2) {
								r=query(i+1,j);
								break;
							}
						}
						if (r == 0) cout<<"! 1"<<endl;
						else cout<<"! 2"<<endl;
					}
				}
				
				else {
					for(int j=1;j<=n;j++) {
						if (j != i and j != i+1 and j != i1) {
							r=query(i,j);
							break;
						}
					}
					if (r == 0) cout<<"! 1"<<endl;
					else cout<<"! 2"<<endl;
				}
				ok=1;
				break;
			}
		}
	}
	else {
		for(int i=1;i<=n;i+=2) {
			int res=query(i,i+1);
			if (res == 1) {
				int i1;
				int r;
				for(int j=1;j<=n;j++) {
					if (j != i and j != i+1) {
						i1=j;
						r=query(i,j);
						break;
					}
				}
				
				if (r == 0) {
					int i2;
					for(int j=1;j<=n;j++) {
						if (j != i and j != i+1) {
							i2=j;
							r=query(i+1,j);
							break;
						}
					}
					if (r == 0) cout<<"! 1"<<endl;
					else {
						for(int j=1;j<=n;j++) {
							if (j != i and j != i+1 and j != i2) {
								r=query(i+1,j);
								break;
							}
						}
						if (r == 0) cout<<"! 1"<<endl;
						else cout<<"! 2"<<endl;
					}
				}
				else {
					for(int j=1;j<=n;j++) {
						if (j != i and j != i+1 and j != i1) {
							r=query(i,j);
							break;
						}
					}
					if (r == 0) cout<<"! 1"<<endl;
					else cout<<"! 2"<<endl;
				}
				
				ok=1;
				break;
			}
		}
	}
	if (!ok) cout<<"! 1"<<endl;
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







