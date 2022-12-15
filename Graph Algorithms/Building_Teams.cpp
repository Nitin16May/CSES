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

void bfs(int v,int e,dvec &g)
{
    vector<int> vis(v+1,0);
    bool ans=true;
    queue<pair<int,int>> q;
    f(i,1,v)
    {
        if(vis[i]!=0)continue;
        q.push({i,1});vis[i]=1;
        while(q.size())
        {
            pair<int,int> x=q.front();q.pop();
            for(auto i:g[x.first])
            {
                if(vis[i]==0)
                {
                    if(x.second==1)vis[i]=2;
                    else vis[i]=1;
                    q.push({i,vis[i]});
                }
                else if(vis[i]==x.second)ans=false;
            }
        }
    }
    if(!ans)cout << "IMPOSSIBLE\n";
    else f(i,1,v)cout << vis[i] << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v+1);
    f(i,1,e)
    {
        int vert1,vert2;
        cin >> vert1 >> vert2;
        graph[vert1].push_back(vert2);
        graph[vert2].push_back(vert1);
    }
    bfs(v,e,graph);
}
