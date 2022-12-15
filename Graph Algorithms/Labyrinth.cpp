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

//************Nitin1605************

void ans(vector<vector<char>> &a,int n,int m)
{
    int ax=-1,ay=-1,x=-1,y=-1;
    f(i,1,n)f(j,1,m)if(a[i][j]=='A')ax=i,ay=j;
    f(i,1,n)f(j,1,m)if(a[i][j]=='B')x=i,y=j;
    queue<array<int,3>> q;q.push({ax,ay,0});
    dvec lvl(n+2,vec(m+2,1000000000)),vis(n+2,vec(m+2,0));
    while(q.size())
    {
        array<int,3> p=q.front();q.pop();
        if(vis[p[0]][p[1]])continue;vis[p[0]][p[1]]=1;
        lvl[p[0]][p[1]]=p[2];
        //if(a[p[0]+1][p[1]]=='B' || a[p[0]-1][p[1]]=='B' || a[p[0]][p[1]+1]=='B' || a[p[0]][p[1]-1]=='B')break;
        if(a[p[0]+1][p[1]]=='.')q.push({p[0]+1,p[1],p[2]+1});
        if(a[p[0]-1][p[1]]=='.')q.push({p[0]-1,p[1],p[2]+1});
        if(a[p[0]][p[1]+1]=='.')q.push({p[0],p[1]+1,p[2]+1});
        if(a[p[0]][p[1]-1]=='.')q.push({p[0],p[1]-1,p[2]+1});
    }
    int ans=min({lvl[x+1][y],lvl[x-1][y],lvl[x][y+1],lvl[x][y-1]});
    if(ans==1000000000){no;return;}
    string s=string(ans+1,'-'),d="DULR?";
    fr(i,ans,0)
    {
        array<int,4> lol={1000000000,0,0,4};
        if(lvl[x-1][y]<lol[0])lol={lvl[x-1][y],x-1,y,0};
        if(lvl[x+1][y]<lol[0])lol={lvl[x+1][y],x+1,y,1};
        if(lvl[x][y+1]<lol[0])lol={lvl[x][y+1],x,y+1,2};
        if(lvl[x][y-1]<lol[0])lol={lvl[x][y-1],x,y-1,3};
        s[i]=d[lol[3]];x=lol[1];y=lol[2];
    }
    cout << "YES\n" << ans+1 << endl << s;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n+2,vector<char>(m+2,'#'));
    f(i,1,n)f(j,1,m)cin >> a[i][j];
    ans(a,n,m);
}