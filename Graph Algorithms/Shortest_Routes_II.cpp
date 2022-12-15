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


int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,m,q,x,y,z;
    cin>>n>>m>>q;
    dvec dist(n+1,vec (n+1,1e16));
    f(i,1,m)
    {
        cin >> x >> y >> z;
        dist[x][y]=min(dist[x][y],z);
        dist[y][x]=min(dist[y][x],z);
    }
    f(i,1,n)dist[i][i]=0;
    f(i,1,n)f(j,1,n)f(k,1,n)dist[j][k]=min(dist[j][k],min((int)1e16,dist[j][i]+dist[i][k]));
    f(i,1,n)f(j,1,n)if(dist[i][j]==1e16)dist[i][j]=-1;
    f(i,1,q)
    {
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
}
