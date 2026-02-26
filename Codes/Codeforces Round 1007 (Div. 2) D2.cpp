// Problem: D2. Infinite Sequence (Hard Version)
// Contest: Codeforces - Codeforces Round 1007 (Div. 2)
// URL: https://codeforces.com/contest/2071/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i32 = int;
#define int long long
using namespace std;

int n,l,r;
map<int,int> pb;
vector<i32> a;
vector<i32> b;
vector<i32> aprefix;
vector<i32> bprefix;

int geta(int x);
int getb(int x);
int prea(int x);
int preb(int x);

int geta(int x)
{
	if (x <= 2*n+1) return a[x];
	return getb(x/2);
}

int getb(int x)
{
	if (x <= 2*n+1) return b[x];
	if (x%2 == 1) return b[n];
	else return b[n]^geta(x);
}

int prea(int x)
{
	if (x <= 2*n+1) return aprefix[x];	
	if (x%2 == 0) return geta(x)+prea(x-1);
	int res=prea(x/2)+2*(  preb(x/2)-preb((x/2+1)/2-1)  );
	if (x/2%2 == 0) res-=getb((x/2+1)/2);
	return res;
}

int preb(int x)
{
	if (x <= 2*n+1) return bprefix[x];
	if (pb.find(x) != pb.end()) return pb[x];
	if (x%2 == 0) return getb(x)+preb(x-1);
	int res;
	
	if (b[n] == 0) {
		if (x/2%2 == 1) res=2*preb(x/2)-preb((x/2+1)/2-1);
		else if (x/2%2 == 0) res=2*preb(x/2)-preb((x/2+1)/2);
	}
	else {
		if (x/2%2 == 1) res=(x-x/2)+preb((x/2+1)/2-1);
		else if (x/2%2 == 0) res=(x-x/2)+preb((x/2+1)/2);
	}
	
	pb[x]=res;
	return res;
}

void solve()
{
	pb.clear();
	cin>>n>>l>>r;
	if (n%2 == 0) {
		n++;
		a.assign(2*n+2,0);
		b.assign(2*n+2,0);
		for(int i=1;i<=n-1;i++) cin>>a[i];
		for(int i=1;i<=n-1;i++) b[i]=b[i-1]^a[i];
		a[n]=b[n/2];
		b[n]=b[n-1]^a[n];
		for(int i=n+1;i<=2*n+1;i++) a[i]=b[i/2];
		for(int i=n+1;i<=2*n+1;i++) b[i]=b[i-1]^a[i];
	}
	else {
		a.assign(2*n+2,0);
		b.assign(2*n+2,0);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
		for(int i=n+1;i<=2*n+1;i++) a[i]=b[i/2];
		for(int i=n+1;i<=2*n+1;i++) b[i]=b[i-1]^a[i];
	}
	
	aprefix.assign(2*n+2,0);
	bprefix.assign(2*n+2,0);
	for(int i=1;i<=2*n+1;i++) aprefix[i]=aprefix[i-1]+a[i];
	for(int i=1;i<=2*n+1;i++) bprefix[i]=bprefix[i-1]+b[i]; 
	
	cout<<prea(r)-prea(l-1)<<endl;
	
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









