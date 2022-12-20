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
    int x,y,z=LLONG_MAX;
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
            int vert1,vert2,xx;
            cin >> vert1 >> vert2 >> xx;
            g[vert1].push_back({vert2,xx});
            g[vert2].push_back({vert1,xx});
            if(xx<z)
            {
                z=xx;
                x=vert1;
                y=vert2;
            }
        }
    }
};
void solve(Graph &a)
{
    int ans=a.z,tn=0;
    const auto comp = [](auto &a, auto &b){return a.second > b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
    q.push({a.x,0});
    q.push({a.y,0});
    while(q.size())
    {
        auto s=q.top();
        q.pop();
        if(a.vis[s.first])continue;
        a.vis[s.first]=1;
        ans+=s.second;tn++;
        for(auto j:a.g[s.first])if(a.vis[j.first]==0)q.push({j});
    }
    if(tn==a.v)cout << ans;
    else cout << "IMPOSSIBLE";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    Graph a;
    int n,m;
    cin >> n >> m;
    a.alloc(n);
    a.addEdges(m);
    solve(a);
}
