#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while (t--)
	{
		int flag=0;
		string s;
		cin>>s;
		int len=s.length();
		for(int i=0;i<len-1;i++){
			if (s[i] == s[i+1]){
				cout<<s[i]<<s[i+1]<<endl;
				flag=1;
				break;
			}
		}
		if (flag) continue;
		for(int i=0;i<len-2;i++){
			if (s[i] != s[i+1] and s[i+1] != s[i+2] and s[i] != s[i+2]){
				cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
				flag=1;
				break;
			}
		}
		if (!flag) {cout<<-1<<endl;continue;}
	}
	return 0;
}





