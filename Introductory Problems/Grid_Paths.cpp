#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define llceil(a,b) ceil(((double)a)/((double)b))
#define llfloor(a,b) floor(((double)a)/((double)b))
#define vec vector<ll>
#define dvec vector<vector<ll>>
//////*************Nitin1605***************//////
string s;
dvec a(7,vec (7,0));
ll answer(ll x,ll y,ll n)
{
    ll u=0,d=0,l=0,r=0,ans=0;
    if(n==48)
    {
        if(x==6 && y==0)return 1;
        else return 0;
    }
    if(a[6][0]==1)return 0;
    if(x!=0)if(a[x-1][y]==0)u=1;
    if(x!=6)if(a[x+1][y]==0)d=1;
    if(y!=0)if(a[x][y-1]==0)l=1;
    if(y!=6)if(a[x][y+1]==0)r=1;
    if(d==0 && u==0 && l==1 && r==1)return 0;
    if(d==0 && u==0 && l==1 && r==1)return 0;
    if(l==0 && r==0 && u==1 && d==1)return 0;
    if(l==0 && r==0 && u==1 && d==1)return 0;
    if(s[n]=='R')l=u=d=0;
    if(s[n]=='L')r=u=d=0;
    if(s[n]=='U')l=r=d=0;
    if(s[n]=='D')l=r=u=0;
    if(u==1)
    {
        a[x-1][y]=1;
        ans+=answer(x-1,y,n+1);
        a[x-1][y]=0;
    }
    if(d==1)
    {
        a[x+1][y]=1;
        ans+=answer(x+1,y,n+1);
        a[x+1][y]=0;
    }
    if(l==1)
    {
        a[x][y-1]=1;
        ans+=answer(x,y-1,n+1);
        a[x][y-1]=0;
    }
    if(r==1)
    {
        a[x][y+1]=1;
        ans+=answer(x,y+1,n+1);
        a[x][y+1]=0;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> s;
    a[0][0]=1;
    cout << answer(0,0,0);
}