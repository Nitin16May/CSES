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

void tour(int x,dvec &g,vector<bool> &vis)
{
    if(vis[x])return;
    vis[x]=true;
    for(auto i:g[x])tour(i,g,vis);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,r;
    cin >> n >> r;
    dvec g(n+1);
    vector<bool> vis(n+1,false);
    vec ans;
    f(i,1,r)
    {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    f(i,1,n)
    {
        if(vis[i])continue;
        ans.pb(i);
        tour(i,g,vis);
    }
    cout << ans.size()-1 << endl;
    f(i,0,sz(ans)-2)cout << ans[i] << " " << ans[i+1] << endl;
}
