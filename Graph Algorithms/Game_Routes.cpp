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
    int v;
    vector<vector<int>> g;
    vector<int> vis;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<int>> (x+1);
        vis=vector<int> (x+1);
    }
    void addEdges(int e)
    {
        f(i,1,e)
        {
            int vert1,vert2;
            cin >> vert1 >> vert2;
            g[vert1].push_back(vert2);
        }
    }
    void invert(Graph &inv)
    {
        inv.alloc(v);
        f(i,1,v)for(auto j:g[i])inv.g[j].push_back(i);
    }
};
vec topoSort(Graph &a)
{
    vector<int> indeg(a.v+1,0);
    f(i,1,a.v)for(auto j:a.g[i])indeg[j]++;
    queue<int> ans;
    vector<int> ok;
    f(i,1,a.v)if(indeg[i]==0)ans.push(i);
    while(ans.size())
    {
        ok.push_back(ans.front());
        for(auto i:a.g[ans.front()])
        {
            indeg[i]--;
            if(indeg[i]==0)ans.push(i);
        }
        ans.pop();
    }
    return ok;
}
void print(Graph &a,Graph &b,vector<int> &topo)
{
    vec ways(a.v+1,0),father(a.v+1,0);
    ways[1]=1;
    f(i,0,a.v-1)
    {
        if(topo[i]==1)continue;
        for(auto j:b.g[topo[i]])
        {
            ways[topo[i]]+=ways[j];
            ways[topo[i]]=ways[topo[i]]%1000000007;
        }
    }
    cout << ways[a.v] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    Graph a,b;
    int n,m;
    cin >> n >> m;
    a.alloc(n);
    a.addEdges(m);
    vec topo=topoSort(a);
    a.invert(b);
    print(a,b,topo);
}