#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define float long double
#define double long double
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(int i = a; i <= b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define vec vector<int>
#define dvec vector<vector<int>>
#define pb push_back
//************Nitin1605************
int m,n,ax,ay;
void spreadA(int x,int y,vector<vector<char>> &a, dvec &b)
{
    queue<array<int,3>> q;
    q.push({0,x,y});
    map<pair<int,int>,bool> vis;
    while(q.size())
    {
        auto s=q.front();q.pop();
        if(s[1]!=x || s[2]!=y)if(b[s[1]][s[2]]<=s[0] || a[s[1]][s[2]]=='#' || a[s[1]][s[2]]=='M' || vis[{s[1],s[2]}])continue;
        b[s[1]][s[2]]=s[0];vis[{s[1],s[2]}]=true;
        q.push({s[0]+1,s[1]+1,s[2]});
        q.push({s[0]+1,s[1]-1,s[2]});
        q.push({s[0]+1,s[1],s[2]+1});
        q.push({s[0]+1,s[1],s[2]-1});
    }
}
void spreadB(vector<vector<char>> &a, dvec &b, dvec &c)
{
    queue<array<int,3>> q;
    vector<vector<bool>> vis(n+2,vector<bool>(m+2,false));
    f(i,1,n)
    {
        f(j,1,m)
        {
            if(a[i][j]=='M'){q.push({0,i,j});vis[i][j]=true;}
            else if(a[i][j]=='A'){spreadA(i,j,a,c);c[i][j]=0;}
            else if(a[i][j]=='#')b[i][j]=0;
        }
    }
    while(q.size())
    {
        auto s=q.front();q.pop();
        b[s[1]][s[2]]=s[0];
        if(a[s[1]+1][s[2]]!='#' && !vis[s[1]+1][s[2]]){q.push({s[0]+1,s[1]+1,s[2]});vis[s[1]+1][s[2]]=true;}
        if(a[s[1]-1][s[2]]!='#' && !vis[s[1]-1][s[2]]){q.push({s[0]+1,s[1]-1,s[2]});vis[s[1]-1][s[2]]=true;}
        if(a[s[1]][s[2]+1]!='#' && !vis[s[1]][s[2]+1]){q.push({s[0]+1,s[1],s[2]+1});vis[s[1]][s[2]+1]=true;}
        if(a[s[1]][s[2]-1]!='#' && !vis[s[1]][s[2]-1]){q.push({s[0]+1,s[1],s[2]-1});vis[s[1]][s[2]-1]=true;}
    }
}
vector<char> ans;
void backtrack(dvec &c,int x,int y)
{
    if(c[x][y]==0)
    {
        fr(i,ans.size()-1,0)cout << ans[i];
        return;
    }
    if(c[x+1][y]==c[x][y]-1){ans.pb('U');return backtrack(c,x+1,y);}
    if(c[x-1][y]==c[x][y]-1){ans.pb('D');return backtrack(c,x-1,y);}
    if(c[x][y+1]==c[x][y]-1){ans.pb('L');return backtrack(c,x,y+1);}
    if(c[x][y-1]==c[x][y]-1){ans.pb('R');return backtrack(c,x,y-1);}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    cin>>n>>m;
    vector<vector<char>> a(n+2,vector<char>(m+2,'#'));
    dvec b(n+2,vec(m+2,1e9)),c(n+2,vec(m+2,1e9));
    f(i,1,n)f(j,1,m)cin >> a[i][j];
    spreadB(a,b,c);
    f(i,1,n)
    {
        if(c[i][1]<b[i][1]){yes;cout << c[i][1] << endl;backtrack(c,i,1);return 0;}
        if(c[i][m]<b[i][m]){yes;cout << c[i][m] << endl;backtrack(c,i,m);return 0;}
    }
    f(i,1,m)
    {
        if(c[1][i]<b[1][i]){yes;cout << c[1][i] << endl;backtrack(c,1,i);return 0;}
        if(c[n][i]<b[n][i]){yes;cout << c[n][i] << endl;backtrack(c,n,i);return 0;}
    }
    no;
}