// Problem: J - Merge Sequences
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/J
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    
    vector<array<int,2>> a(n+m);
    for(int i=0;i<n+m;i++) {
    	cin>>a[i][0];
    	a[i][1]=i;
    }
    inplace_merge(a.begin(),a.begin()+n,a.end());
    
    vector<int> p(n+m);
    for(int i=0;i<n+m;i++) {
    	p[a[i][1]]=i;
    }
    for (int i=0;i<n;i++) {
    	cout<<p[i]+1<<" ";
    }
    cout<<"\n";
    for(int i=0;i<m;i++) {
    	cout<<p[i+n]+1<<" ";
    }
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









