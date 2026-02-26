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

void solve()
{
	int n,m;
	cin>>n>>m;
	if (n*m%4 != 0 or (n == 2 and m == 2)) {cout<<"NO\n";return;}
	vector a(n,vector<int>(m));
	auto P=[&]() -> void {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<a[i][j]<<" \n"[j == m-1];
			}
		}	
	};
	
	
	
	cout<<"YES\n";
	int cnt=1;
	if (n%4 == 0) {
		for(int k=0;k<n/4;k++) {
			for(int j=0;j<m;j++) {
				for(int i=k*4;i<k*4+4;i++) {
					a[i][j]=cnt;
				}
				cnt++;
			}
		}
	}
	else if (m%4 == 0) {
		for(int k=0;k<m/4;k++) {
			for(int i=0;i<n;i++) {
				for(int j=k*4;j<k*4+4;j++) {
					a[i][j]=cnt;
				}
				cnt++;
			}
		}
	}
	else if (n >= 6 and (n-6)%4 == 0) {
		for(int k=0;k<m;k+=2) {
			a[0][k]=cnt;a[0][k+1]=cnt;
			a[1][k]=cnt;a[1][k+1]=cnt+2;
			a[2][k]=cnt;a[2][k+1]=cnt+2;
			a[3][k]=cnt+1;a[3][k+1]=cnt+2;
			a[4][k]=cnt+1;a[4][k+1]=cnt+2;
			a[5][k]=cnt+1;a[5][k+1]=cnt+1;
			cnt+=3;
		}
		for(int k=0;k<(n-6)/4;k++) {
			for(int j=0;j<m;j++) {
				for(int i=6+k*4;i<6+k*4+4;i++) {
					a[i][j]=cnt;
				}
				cnt++;
			}
		}
	}
	else if (m >= 6 and (m-6)%4 == 0) {
		for(int k=0;k<n;k+=2) {
			a[k][0]=cnt;a[k][1]=cnt;a[k][2]=cnt;a[k][3]=cnt+1;a[k][4]=cnt+1;a[k][5]=cnt+1;
			a[k+1][0]=cnt;a[k+1][1]=cnt+2;a[k+1][2]=cnt+2;a[k+1][3]=cnt+2;a[k+1][4]=cnt+2;a[k+1][5]=cnt+1;
			cnt+=3;
		}
		for(int k=0;k<(m-6)/4;k++) {
			for(int i=0;i<n;i++) {
				for(int j=6+k*4;j<6+k*4+4;j++) {
					a[i][j]=cnt;
				}
				cnt++;
			}
		}
	}
	P();
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









