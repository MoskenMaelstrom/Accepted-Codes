#include<bits/stdc++.h>	
using namespace std;

void solve()
{
    int n,nv=0,pv=-1;
    long long dis=0;
    string s;
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) {
        // 处理恢复操作
        if (pv != -1) {
            nv = pv;
            pv = -1;
        }
        
        char op = s[i];
        if (op == '0') {
            nv += 10;
            dis += nv;
        }
        else if (op == '1') {
            nv = max(nv - 5, 0);
            dis += nv;
        }
        else if (op == '2') {
            int ns = max(nv - 10, 0);
            dis += ns;
            pv = nv;
            nv = ns;
        }
    }
    
    cout << dis << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









