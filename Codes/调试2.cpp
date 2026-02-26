#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
char a[305][305];
struct point{
    int x,y,step;
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n,m,sx,sy;
int x11,y11,x22,y22;    //标记一对传送门
void work()
{
    rep(i,n)
        rep(j,m){
            if (i == x11 and j == y11) continue;
            if (a[x11][y11] == a[i][j]){
                x22=i;
                y22=j;
                return;
            }
        }
}
signed main()
{
    cin>>n>>m;
    rep(i,n) rep(j,m) cin>>a[i][j];
    rep(i,n) rep(j,m) if (a[i][j] == '@') {sx=i;sy=j;break;}
    queue<point> q;
    point sp,np,p0;
    sp={sx,sy,0};
    q.push(sp);
    while (!q.empty())
    {
        np=q.front();
        q.pop();
        rep(i,4){
            int x=np.x+dx[i];
            int y=np.y+dy[i];
            if (x < 0 or x > n-1 or y < 0 or y > m-1 or a[x][y] == '#') continue;
            if (a[x][y] == '.') {
                p0={x,y,np.step+1};
                q.push(p0);
            }
            else if (a[x][y] == '=') {cout<<np.step+1;return 0;}
            else {
                x11=np.x;
                y11=np.y;
                work();
                p0={x22,y22,np.step+1};
                q.push(p0);
            }
        }
    }
    return 0;
}