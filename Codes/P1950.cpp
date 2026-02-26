// Problem: 
//     P1950 长方形
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1950
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//思路:一行一行来，考虑每一行的某个元素时，考虑向上延伸的高度
//向左就一直延伸就行，向右碰到一样高的就停
#include<bits/stdc++.h>
#define int long long
using namespace std;

char a[1005][1005];
int h[1005][1005];
int l[1005][1005];
int r[1005][1005];

signed main()
{
	//输入
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {l[i][j]=j;r[i][j]=j;}//初始化l和r
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	
	//处理h
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if (a[i][j] == '.') h[i][j]=h[i-1][j]+1;
		}
	}	
	
	//处理l
	for(int i=1;i<=n;i++) {
		stack<int> ddz;
		for(int j=m;j>=1;j--) {
			if (ddz.empty() or h[i][ddz.top()] <= h[i][j]) ddz.push(j);
			else {
				while (!ddz.empty() and h[i][ddz.top()] > h[i][j]) {
					l[i][ddz.top()]=j+1;
					ddz.pop();
				}
				ddz.push(j);
			}
		}
		while (!ddz.empty()) {
			l[i][ddz.top()]=1;
			ddz.pop();
		}
	}
	
	//处理r
	for(int i=1;i<=n;i++) {
		stack<int> ddz;//存j
		for(int j=1;j<=m;j++) {
			if (ddz.empty() or h[i][ddz.top()] < h[i][j]) ddz.push(j);
			else {
				while (!ddz.empty() and h[i][ddz.top()] >= h[i][j]) {
					r[i][ddz.top()]=j-1;
					ddz.pop();
				} 
				ddz.push(j);
			}
		}
		//清空ddz
		while (!ddz.empty()) {
			r[i][ddz.top()]=m;//到最后有界都是m
			ddz.pop();
		} 
	}
	//输出
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if (a[i][j] == '.') {
				if (j-l[i][j] == 0 and r[i][j]-j == 0) ans+=h[i][j];
				else if (j-l[i][j] == 0) ans+=h[i][j]*(r[i][j]-j+1);
				else if (r[i][j]-j == 0) ans+=h[i][j]*(j-l[i][j]+1);
				else ans+=(j-l[i][j]+1)*(r[i][j]-j+1)*h[i][j];
			}
	cout<<ans;
	return 0;
}

// 		
	// for(int i=1;i<=n;i++) {
		// for(int j=1;j<=m;j++) cout<<l[i][j]<<" ";
		// cout<<"\n";
	// }
	// cout<<"\n";
	// for(int i=1;i<=n;i++) {
		// for(int j=1;j<=m;j++) cout<<r[i][j]<<" ";
		// cout<<"\n";
	// }
// 	

















