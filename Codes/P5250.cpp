// Problem: 
//     P5250 【深基17.例5】木材仓库
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5250
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int t;
	cin>>t;
	set<int> st;
	while (t--){
		int a1,a2;
		cin>>a1>>a2;
		if (a1 == 1) {
			if (st.find(a2) != st.end()) cout<<"Already Exist\n";
			else st.insert(a2);
		}
		else {
			if (st.empty()) cout<<"Empty\n";
			else {
				if (st.find(a2) != st.end()) 
					{cout<<a2<<endl;st.erase(a2);continue;}	//能找到a2就直接用a2
					
				auto pos1 = st.upper_bound(a2);		//>a2的第一个数
				auto pos2 = --st.lower_bound(a2);	//<a2的最后一个数
				if (st.lower_bound(a2) == st.begin()) 
					{cout<<*pos1<<endl;st.erase(pos1);continue;}
					
				if (pos1 == st.end() or abs(*pos1-a2) > abs(*pos2-a2))
					{cout<<*pos2<<endl;st.erase(pos2);}
				else if (abs(*pos1-a2) == abs(*pos2-a2))
				{
					if (*pos1 > *pos2) {cout<<*pos2<<endl;st.erase(pos2);}
					else {cout<<*pos1<<endl;st.erase(pos1);}
				}
				else 
					{cout<<*pos1<<endl;st.erase(pos1);}
			}
		}
	}
	return 0;
}




