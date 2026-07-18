// Problem: H. Link与矩阵除法
// Contest: Codeforces - 2025年北京市大学生程序设计竞赛暨“小米杯”全国邀请赛
// URL: https://codeforces.com/gym/105851/problem/H
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m,p;
	cin>>n>>m>>p;
	vector<bitset<2001>> A(n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int x;
			cin>>x;
			A[i][j]=x;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=m;j<m+p;j++) {
			int x;
			cin>>x;
			A[i][j]=x;
		}
	}
	
    int row=0;
    for(int col=0;col<m;col++) {
        int r=row;
        while (r < n and !A[r][col]) r++;
        if (r == n) continue;
        if (r != row) swap(A[r],A[row]);

        for(int k=0;k<n;k++) {
            if (k != row and A[k][col]) A[k]^=A[row];
        }
        row++;
        if (row == n) break;
    }
    
    for(int i=row;i<n;i++) {
    	for(int j=m;j<m+p;j++) {
    		if (A[i][j]) {
    			cout<<"No\n";
    			return;
    		}
    	}
    }
    
    cout<<"Yes\n";
    row=0;
    for(int col=0;col<m;col++) {
    	if (!A[row][col]) {
    		for(int j=0;j<p;j++) cout<<"0 ";
    		cout<<"\n";
    	}
    	else {
    		for(int j=m;j<m+p;j++) cout<<A[row][j]<<" ";
    		cout<<"\n";
    		row++;
    	}
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







