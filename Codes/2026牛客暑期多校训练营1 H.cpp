// Problem: Rock-Paper-Scissors Master
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133876/H
// Memory Limit: 2048 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
double f[729][1001];
int pow3[]={1,3,9,27,81,243,729};
int get1(int s,int p1,int p2) {
	int n1=s/pow3[p1]%3;
	int n2=s/pow3[p2+3]%3;
	if (n1 == n2) return 1;
	else if ((n1+1)%3 == n2) return 3;
	else return 0;
}
double get2(int s,int p1,int p2,int k) {
	double sum=0;
	int n1=s/pow3[p1]%3;
	int n2=s/pow3[p2+3]%3;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			sum+=f[s-n1*pow3[p1]+i*pow3[p1]-n2*pow3[p2+3]+j*pow3[p2+3]][k-1];
		}
	}
	return sum/9;
}

double x;
void solve()
{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int s=0;
	for(int i=0;i<3;i++) {
		if (s1[i] == 'S') s+=pow3[i];
		if (s1[i] == 'P') s+=2*pow3[i];
		if (s2[i] == 'S') s+=pow3[i+3];
		if (s2[i] == 'P') s+=2*pow3[i+3];
	}
	// cout<<fixed<<setprecision(10)<<f[s][1]<<"\n";
	
	if (n <= 1000) cout<<fixed<<setprecision(10)<<f[s][n]<<"\n";
	else cout<<fixed<<setprecision(10)<<f[s][1000]+(n-1000)*x<<"\n";
}

signed main()
{
	for(int k=1;k<=1000;k++) {
		for(int s=0;s<729;s++) {
			double maxx=0;
			for(int i=0;i<3;i++) {
				double minx=inf;
				for(int j=0;j<3;j++) {
					minx=min(minx,get1(s,i,j)+get2(s,i,j,k));
				}
				maxx=max(maxx,minx);
			}
			f[s][k]=maxx;
		}
	}
	x=f[123][1000]-f[123][999];
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







