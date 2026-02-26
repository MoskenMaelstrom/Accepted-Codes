#include <bits/stdc++.h>
using namespace std;

int a[2005];
int n, p;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    int minx = 0;
    for (int i = 1; i <= n; i++) 
        minx = max(minx, a[i] - i + 1);

    vector<int> good_x;
    int max_candidate = *max_element(a+1, a+n+1) + n; // 足够大的x上界

    for (int x = minx; x <= max_candidate; x++) {
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            int cnt = upper_bound(a + 1, a + n + 1, x + i - 1) - a - 1;//i为当前遍历到的敌人序号
            if (cnt < i) { valid = false; break; } // f(x)=0
            //如果现在刚好覆盖多出p人，即实力已经在某步积累到覆盖后面p人了，说明找到上界了
            if ((cnt - i + 1) % p == 0) { valid = false; break; }
        }
        if (valid) good_x.push_back(x);
    }

    cout << good_x.size() << '\n';
    for (int x : good_x) cout << x << ' ';
    cout << '\n';
}
