#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,a,b) for(int i = a; i <= b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define sz(x) ((int)(x).size())
//************Nitin1605************
class Graph 
{
    public:
    int v;
    vector<vector<pair<int,int>>> g;
    vector<int> vis;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<pair<int,int>>> (x+1);
        vis=vector<int> (x+1,0);
    }
    void addEdges(int e)
    {
        f(i,1,e)
        {
            int vert1,vert2,x;
            cin >> vert1 >> vert2 >> x;
            g[vert1].push_back({vert2,x});
        }
    }
};
vector<int> ans;int k;
void the_D_algo(Graph &a,int ok)
{
    const auto comp = [](auto &a, auto &b){return a.second > b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
    q.push({ok,0});
    while (!q.empty())
    {
        auto i = q.top();
        q.pop();
        if(i.first==a.v)ans.push_back(i.second);
        a.vis[i.first]++;
        if(sz(ans)==k)break;
        if(a.vis[i.first]<=k)for (auto j : a.g[i.first])q.push({j.first, i.second+j.second});
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    int n,e;
    cin >> n >> e >> k;
    Graph a;
    a.alloc(n);
    a.addEdges(e);
    the_D_algo(a,1);
    for(auto i:ans)cout << i << " ";
}