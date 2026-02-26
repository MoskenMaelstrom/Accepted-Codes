#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int gcd(int a1,int a2)
{
	if (a1>a2) swap(a1,a2);
	return a1 ? gcd(a2%a1,a1) : a2;
}
int lcm(int a1,int a2)
{
	return a1*a2/gcd(a1,a2);
}
signed main()
{
	cout<<lcm(35,10);
	
}