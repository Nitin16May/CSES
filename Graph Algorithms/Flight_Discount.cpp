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
    vector<vector<pair<int,int>>> g;
    vector<int> dist;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<pair<int,int>>> (x+1);
        dist=vector<int> (x+1,1e15);
    }
    void addEdges(int e)
    {
        this->e=e;
        f(i,1,e)
        {
            int vert1,vert2,x;
            cin >> vert1 >> vert2 >> x;
            g[vert1].push_back({vert2,x});
            //g[vert2].push_back(vert1);
        }
    }
    void invert(Graph &inv)
    {
        inv.alloc(v);
        f(i,1,v)for(auto j:g[i])inv.g[j.first].push_back({i,j.second});
    }
};

void the_D_algo(Graph &a, int s)
{
    a.dist[s] = 0;
    const auto comp = [](auto &a, auto &b){return a.second > b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
    q.push({s,0});
    while (!q.empty())
    {
        auto i = q.top();
        q.pop();
        if (i.second > a.dist[i.first])continue;
        for (auto j : a.g[i.first])
        {
            if (a.dist[j.first] > a.dist[i.first] + j.second)
            {
                a.dist[j.first] = a.dist[i.first] + j.second;
                q.push({j.first, a.dist[j.first]});
            }
        }
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
    Graph a,inva;
    int n,m;
    cin >> n >> m;
    a.alloc(n);
    a.addEdges(m);
    a.invert(inva);the_D_algo(a,1);the_D_algo(inva,n);
    int ans=a.dist[n];
    f(i,1,n)for(auto j:a.g[i])ans=min(ans,a.dist[i]+inva.dist[j.first]+j.second/2);
    cout << ans;
}