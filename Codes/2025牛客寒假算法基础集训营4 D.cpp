#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n1,n2;
	string s1,s2;
	cin>>n1>>n2;
	cin>>s1>>s2;
	vector<int> a1(26,0);
	vector<int> a2(26,0);
	if (n1 < n2) {swap(n1,n2);swap(s1,s2);}
	for(int i=0;i<n1;i++) a1[s1[i]-'a']++;
	for(int i=0;i<n2;i++) a2[s2[i]-'a']++;
	
	for(int i=0;i<26;i++) {
		int tmp=min(a1[i],a2[i]);
		a1[i]-=tmp;
		a2[i]-=tmp;
	}
	
	int rest1=0,rest2=0;
	int p1=0;//算长的那个有几个数字可以操作
	for(auto ele : a1) {rest1+=ele;p1+=ele/2;}
	for(auto ele : a2) {rest2+=ele;}
	p1*=2;
	int k=abs(rest1-rest2);
	k=min(k,p1);
	cout<<(rest1+rest2-k)/2<<endl;
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









