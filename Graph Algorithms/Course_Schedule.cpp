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
};

void topoSort(Graph &a)
{
    vector<int> indeg(a.v+1,0);
    f(i,1,a.v)for(auto j:a.g[i])indeg[j]++;
    queue<int> ans;
    vector<int> ansv;
    f(i,1,a.v)if(indeg[i]==0)ans.push(i);
    while(ans.size())
    {
        ansv.push_back(ans.front());
        for(auto i:a.g[ans.front()])
        {
            indeg[i]--;
            if(indeg[i]==0)ans.push(i);
        }
        ans.pop();
    }
    if(ansv.size()<a.v){cout << "IMPOSSIBLE\n";return;}
    for(auto i:ansv)cout << i << " ";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    Graph a;
    int n,m;
    cin >> n >> m;
    a.alloc(n);
    a.addEdges(m);
    topoSort(a);
}
