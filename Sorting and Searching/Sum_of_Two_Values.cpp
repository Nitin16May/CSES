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
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ll n,x,s,ans=-1;
    cin >> n >> s;
    map<ll,vec> a;
    f(i,1,n)
    {
        cin >> x;
        a[x].pb(i);
    }
    if(s%2==0 && a[s/2].size()>=2)
    {
        cout << a[s/2][0] << " " << a[s/2][1] << endl;
    }
    for(auto i:a)
    {
        if(s%2==0 && s/2==i.first)continue;
        if(a[s-i.first].size()>0 && i.second.size()>0){ans=i.first;break;}
    }
    if(ans!=-1)cout << a[ans][0] << " " << a[s-ans][0] << endl;
    else cout << "IMPOSSIBLE";
}