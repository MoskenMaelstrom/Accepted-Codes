#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	int rev=0;
	if (n%3 != 0) rev=1;
	if (n%3 == 0 and m%3 == 0 and n > m) rev=1;
	
	if (rev) swap(n,m);
	vector a(n,vector<int>(m));
	
	if (n == 6 and m == 1) a={{0},{0},{1},{1},{2},{2}};
	else if (n == 6 and m == 2) a={{0,0},{0,0},{1,1},{1,1},{2,2},{2,2}};
	else if (n != 3 and m <= 2) {cout<<"No\n";return;}
	else if (n != 3 and m == 4) {
		rev=1-rev;
		swap(n,m);
		a.assign(n,vector<int>(m,0));
		for(int j=0;j<m;j++) {
			if (j%6 <= 1) a[0][j]=1;
			else if (j%6 <=3) a[0][j]=2;
			else if (j%6 <=5) a[0][j]=0;
		}
		for(int j=0;j<m;j++) {
			if (j%3 == 0) a[1][j]=0;
			if (j%3 == 1) a[1][j]=2;
			if (j%3 == 2) a[1][j]=1;
		}
		for(int j=0;j<m;j++) {
			if ((j+5)%6 <= 1) a[2][j]=0;
			else if ((j+5)%6 <=3) a[2][j]=1;
			else if ((j+5)%6 <=5) a[2][j]=2;
		}
		
		a[3]=a[1];
		if (m%6 != 0) a[3][m-3]=1,a[3][m-1]=0;
	}
	else {
		for(int j=0;j<m;j++) {
			if (j%6 <= 1) a[0][j]=1;
			else if (j%6 <=3) a[0][j]=2;
			else if (j%6 <=5) a[0][j]=0;
		}
		for(int j=0;j<m;j++) {
			if (j%3 == 0) a[1][j]=0;
			if (j%3 == 1) a[1][j]=2;
			if (j%3 == 2) a[1][j]=1;
		}
		for(int j=0;j<m;j++) {
			if ((j+5)%6 <= 1) a[2][j]=0;
			else if ((j+5)%6 <=3) a[2][j]=1;
			else if ((j+5)%6 <=5) a[2][j]=2;
		}
		for(int i=3;i<n;i+=3) {
			a[i]=a[i-1];
			a[i+1]=a[i-2];
			a[i+2]=a[i-3];
		}
	}
	
	if (rev) {
		cout<<"Yes\n";
		for(int j=0;j<m;j++) {
			for(int i=0;i<n;i++) {
				cout<<a[i][j];
			}
			cout<<"\n";
		}
	}
	else {
		cout<<"Yes\n";
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<a[i][j];
			}
			cout<<"\n";
		}
	}
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







