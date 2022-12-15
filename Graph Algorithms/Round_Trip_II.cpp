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
vec path;
vec pathpos(100000,0);
bool dfs(dvec &g,vec &vis,int x)
{
    vis[x]=1;
    // cout << x << "-";for(auto i:path)cout << i << " ";cout << endl;
    // cout << "childs - ";for(auto i:g[x])cout << i << " ";cout << endl;
    for(auto i:g[x])
    {
        // cout << i << endl;
        if(vis[i])
        {
            if(pathpos[i]==0)continue;
            cout << path.size()-pathpos[i]+1 << endl;
            f(j,pathpos[i],path.size()-1)cout << path[j] << " ";cout << i << endl;
            return true;
        }
        if(vis[i]==0)
        {
            pathpos[i]=path.size();path.push_back(i);
            if(dfs(g,vis,i))return true;
            else {path.pop_back();pathpos[i]=0;}
        }
    }
    return false;
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
    vec vis(v+1,0);
    f(i,1,e)
    {
        int vert1,vert2;
        cin >> vert1 >> vert2;
        graph[vert1].push_back(vert2);
    }
    path.push_back(-69);
    f(i,1,v+1)
    {
        if(i==v+1){cout << "IMPOSSIBLE";break;}
        if(vis[i])continue;
        path.push_back(i);pathpos[i]=1;
        if(dfs(graph,vis,i))break;
        else {path.pop_back();pathpos[i]=0;}
    }
    
}
