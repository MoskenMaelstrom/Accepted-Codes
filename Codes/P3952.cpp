// Problem: 
//     P3952 [NOIP2017 提高组] 时间复杂度
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3952
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
bool db(string s1,string s2)//x > y时为1
{
	if (s1 == "n" and s2 != "n") return 1;
	else if (s1 != "n" and s2 != "n" and stoi(s1) > stoi(s2)) return 1;
	return 0;
}
void solve()
{
	int L;
	string S;
	cin>>L>>S;
	S=S.substr(2,S.size()-3);//S变成1或者N^3
	int w=0;//记录O的n有几次方
	if (S != "1") for(int i=2;i<S.size();i++) w=w*10+(S[i]-'0');
	if (S == "1") w=0;
	int n=0;//记录循环里的n有最大有几次方

	bool flag=1;//查语法
	vector<string> zhan1;//模拟栈存变量查重
	vector<int> zhan2;//模拟栈存n的次方
	vector<bool> zhan3;//模拟栈判断是否有效
	for(int i=1;i<=L;i++) {
		string F,j,x,y;
		cin>>F;
		if (F == "F") {
			int n1=0;//临时存的
			if (!zhan2.empty()) n1=zhan2.back();//继承上一次的
			cin>>j>>x>>y;
			//查重
			if (find(zhan1.begin(),zhan1.end(),j) == zhan1.end()) zhan1.push_back(j);
			else flag=0;
			//判断是否有效(上一个无效 或 x > y 的判断为无效)
			if (!zhan3.empty() and !zhan3.back() or db(x,y)) zhan3.push_back(0);//无效数据
			else zhan3.push_back(1);
			//计算n
			if (!db(x,y) and y == "n" and !(x == "n" and y == "n")) zhan2.push_back(n1+1);
			else zhan2.push_back(n1);//同步上一个的值
		}
		else {
			if (zhan1.empty()) {flag=0;continue;}
			if (!zhan3.back()) {zhan1.pop_back();zhan2.pop_back();zhan3.pop_back();continue;}
			n=max(n,zhan2.back());
			zhan1.pop_back();
			zhan2.pop_back();
		}
	}
	if (!zhan1.empty()) flag=0;
	if (!flag) cout<<"ERR\n";//语法错了
	else if (n==w) cout<<"Yes\n";
	else cout<<"No\n";
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