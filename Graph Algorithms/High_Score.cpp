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
class Graph 
{
    public:
    int v,e;
    vector<vector<int>> g;
    vector<array<int,3>> edge;
    vector<int> dist,vis;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<int>> (x+1);
        dist=vector<int> (x+1,LLONG_MAX);
        vis=vector<int> (x+1,0);
    }
    void addEdges(int e)
    {
        this->e=e;
        f(i,1,e)
        {
            int vert1,vert2,x;
            cin >> vert1 >> vert2 >> x;x*=-1;
            edge.push_back({vert1,vert2,x});
            g[vert2].push_back(vert1);
        }
    }
};

bool BellmanFord(Graph &a,int s)//return false if negative cycle occurs
{
    a.dist[s] = 0;
    f(i,1,a.v-1)
    {
        f(j,0,a.e)
        {
            if(!a.vis[a.edge[j][0]] || !a.vis[a.edge[j][1]])continue;
            if (a.dist[a.edge[j][0]]!=LLONG_MAX && a.dist[a.edge[j][0]]+a.edge[j][2]<a.dist[a.edge[j][1]])
            a.dist[a.edge[j][1]]=a.dist[a.edge[j][0]]+a.edge[j][2];
        }
    }
    f(i,0,a.e) 
    {
        if(!a.vis[a.edge[i][0]] || !a.vis[a.edge[i][1]])continue;
        if (a.dist[a.edge[i][0]]!=LLONG_MAX && a.dist[a.edge[i][0]]+a.edge[i][2]<a.dist[a.edge[i][1]])
        return false;
    }
    return true;
}
void dfs(Graph &a,int x)
{
    a.vis[x]=1;
    for(auto i:a.g[x])
    {
        if(a.vis[i]==0)dfs(a,i);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,m;
    Graph a;
    cin >> n >> m;
    a.alloc(n);
    a.addEdges(m);
    dfs(a,n);
    if(BellmanFord(a,1))cout << a.dist[n]*-1;
    else cout << -1;
}
