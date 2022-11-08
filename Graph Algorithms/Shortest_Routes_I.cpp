#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define f(i,a,b) for(ll i = a; i <= b; i++)
//////*************Nitin1605***************//////
vector<vector<pair<ll,ll>>> graph(100001);
vector<ll> dist(100001,LLONG_MAX);
void the_D_algo()
{
    dist[1] = 0;
    const auto comp = [](auto &a, auto &b){return a.second > b.second;};
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(comp)> q(comp);
    q.push({1,0});
    while (!q.empty())
    {
        auto i = q.top();
        q.pop();
        if (i.second > dist[i.first])continue;
        for (auto j : graph[i.first])
        {
            if (dist[j.first] > dist[i.first] + j.second)
            {
                dist[j.first] = dist[i.first] + j.second;
                q.push({j.first, dist[j.first]});
            }
        }
    }
}
int main()
{
    speed;
    ll n,m,u,v,x;
    cin>>n>>m;
    f(i,1,m)
    {
        cin>>u>>v>>x;
        graph[u].push_back({v,x});
    }
    the_D_algo();
    f(i,1,n)
    cout << dist[i] << " ";
 
}