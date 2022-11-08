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
#define llceil(a,b) a/b
#define llfloor(a,b) (a+b-1)/b
#define vec vector<ll>
#define dvec vector<vector<ll>>
//////*************Nitin1605***************//////
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll n,k;
    cin >> n >> k;
    vec a(k),ans(k,0);
    set<ll> c;c.insert(0);c.insert(n);
    f(i,0,k-1)cin >> a[i],c.insert(a[i]);
    for(auto i=c.begin();i!=c.end();i++)
    {
        if(i==c.begin()){n=0;continue;}
        ll a=*i,b=*prev(i);
        ans[k-1]=max(ans[k-1],a-b);
    }
    fr(i,k-1,1)
    {
        auto it=c.find(a[i]);
        ll a=*next(it),b=*prev(it);
        c.erase(it);
        ans[i-1]=max(ans[i],a-b);
    }
    f(i,0,k-1)cout << ans[i] << " ";
}