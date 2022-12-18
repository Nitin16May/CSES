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
    vector<array<int,3>> edge;
    vector<int> dist,father;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<pair<int,int>>> (x+1);
        dist=vector<int> (x+1,1e15);
        father=vector<int> (x+1,0);
    }
    void addEdges(int e)
    {
        this->e=e;
        f(i,1,e)
        {
            int vert1,vert2,x;
            cin >> vert1 >> vert2 >> x;
            edge.push_back({vert1,vert2,x});
        }
    }
};
 
int BellmanFord(Graph &a,int s)//return true if negative cycle occurs
{
    int ret=0;
    a.dist[s] = 0;
    f(i,1,a.v)
    {
        ret=0;
        f(j,0,a.e-1)
        {
            if (a.dist[a.edge[j][0]]+a.edge[j][2]<a.dist[a.edge[j][1]])
            {
                a.dist[a.edge[j][1]]=a.dist[a.edge[j][0]]+a.edge[j][2];
                a.father[a.edge[j][1]]=a.edge[j][0];
                ret=a.edge[j][1];
            }
        }
    }
    return ret;
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
    int ok=BellmanFord(a,1);
    f(i,1,n+3)ok=a.father[ok];
    int x=ok;
    if(ok>0)
    {
        yes;
        stack<int> ans;
        while(true)
        {
            ans.push(x);
            x=a.father[x];
            if(x==ok)break;
        }
        cout << x << " ";
        while(ans.size())
        {
            cout << ans.top() << " ";ans.pop();
        }
    }
    else no;
}