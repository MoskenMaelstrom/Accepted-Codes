#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int pos=-1;
	for(int i=1;i<s.length();i++) if (s[i] == '0') {pos=i;break;}
	//pos现在是第一个0的位置
	if (pos == -1) {cout<<"1 "<<s.length()<<" "<<1<<" "<<1<<endl;return;}
	int maxsum=0,l=0,r=s.length()-pos-1;
	for(int i=0;i<=pos;i++) {//找pos+1次就行
		int p1=pos,p2=i;
		int sum=0;
		while (1)
		{
			if (s[p1] == s[p2]) break;	//一样，直接退出
			if (p1 == s.length()) break;//到底了，退出
			if (s[p1] != s[p2]) sum++;
			p1++;p2++;
		}
		if (maxsum <= sum) {
			l=i;
			r=s.length()-pos-1+i;
			maxsum=max(maxsum,sum);
		}
	}
	cout<<"1 "<<s.length()<<" "<<l+1<<" "<<r+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}