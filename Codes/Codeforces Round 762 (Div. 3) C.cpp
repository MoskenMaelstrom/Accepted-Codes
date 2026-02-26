#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s1,s2,s;
	s2="";
	cin>>s1>>s;
	int pos1=s1.size()-1;
	int pos=s.size()-1;
	for(int i=0;i<pos-pos1;i++) s1="0"+s1;
	pos1=s1.size()-1;
	pos=s.size()-1;
	while (pos != -1)
	{
		if (s[pos] < s1[pos1] and pos >= 1) {
			s2=to_string( stoi(s.substr(pos-1,2))-stoi(s1.substr(pos1,1)) )+s2;
			pos-=2;
			pos1--;
		} else {
			s2=to_string( stoi(s.substr(pos,1))-stoi(s1.substr(pos1,1)) )+s2;
			pos--;
			pos1--;
		}
	}
	int pos2=0;
	while (s2[pos2] == '0') pos2++;
	s2=s2.substr(pos2,s2.size()-pos2);
	string ans=s2;
	
	int len1=s1.size();
	int len2=s2.size();
	if (len1 < len2) {swap(s1,s2);swap(len1,len2);}
	for(int i=0;i<len1-len2;i++) s2="0"+s2;
	string s3="";
	for(int i=0;i<len1;i++) s3+=to_string(s1[i]-'0'+s2[i]-'0');
	int pos3=0;
	while (s3[pos3] == '0') pos3++;
	s3=s3.substr(pos3,s3.size()-pos3);
	if (s3 == s) cout<<ans<<endl;
	else cout<<"-1\n";
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









