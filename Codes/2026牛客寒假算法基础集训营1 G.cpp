// Problem: Digital Folding
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=1e18;
int get(int num) {
	int cnt=0;
	while (num != 0) {
		num/=10;
		cnt++;
	}
	return cnt;
}

int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int rev(int num) {
	int res=0;
	while (num != 0) {
		res*=10;
		res+=num%10;
		num/=10;
	}
	return res;
}

void solve()
{
	int l,r;
	cin>>l>>r;
	
	if (l == r) {cout<<rev(l)<<"\n";return;}
	if (Pow(10,get(r)-1) == r) r--;
	
	int d=get(r);
	for(int i=1;i<=d;i++) {
		int x=r/Pow(10,i-1)%10;
		if (x == 9) continue;
		int rest=r/Pow(10,i);
		if (get(rest-1) == get(rest)) rest--;
		else break;
		if (rest*Pow(10,i)+Pow(10,i)-1 >= l) r=rest*Pow(10,i)+Pow(10,i)-1;
		else break;
	}
	cout<<rev(r)<<"\n";
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







