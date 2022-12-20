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
    vector<vector<pair<int,int>>> g;
    vector<int> vis;
    vector<int> dist;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<pair<int,int>>> (x+1);
        vis=vector<int> (x+1);
        dist=vector<int> (x+1,LLONG_MAX);
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
void the_D_algo(Graph &a)
{
    vector<array<int,5>> val(a.v+1,{0,1000000000000000,10000000000,0,0});
    f(i,1,a.v)val[i][0]=i;
    const auto comp = [](auto &a, auto &b){return a[1] > b[1];};
    priority_queue<array<int,5>, vector<array<int,5>>, decltype(comp)> q(comp);
    q.push({1,0,0,0,1});val[1][1]=0;val[1][2]=0;val[1][4]=1;
    while (!q.empty())
    {
        auto i = q.top();
        q.pop();
        if (i[1] > val[i[0]][1])continue;
        for (auto j : a.g[i[0]])
        {
            if (val[j.first][1] > val[i[0]][1] + j.second)
            {
                val[j.first][1] = val[i[0]][1] + j.second;
                val[j.first][4] = val[i[0]][4]%1000000007;
                val[j.first][2] = val[i[0]][2]+1;
                val[j.first][3] = val[i[0]][3]+1;
                q.push(val[j.first]);
            }
            else if (val[j.first][1] == val[i[0]][1] + j.second)
            {
                val[j.first][4] = (val[j.first][4] + val[i[0]][4])%1000000007;
                val[j.first][2]=min(val[i[0]][2]+1,val[j.first][2]);
                val[j.first][3]=max(val[i[0]][3]+1,val[j.first][3]);
            }
        }
    }
    cout << val[a.v][1] << " " << val[a.v][4] << " " << val[a.v][2] << " " << val[a.v][3];
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
    the_D_algo(a);
}