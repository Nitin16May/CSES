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
    ll n,x,ans=0,q,y;
    cin >> n >> q;
    vec a(n+2,0),hmm(n+1,0);a[0]=n+1;a[n+1]=n+1;
    f(i,1,n)
    {
        cin >> x;
        hmm[i]=x;
        a[x]=i;
    }
    f(i,1,n)if(a[i]<a[i-1])ans++;
    while(q--)
    {
        cin >> x >> y;
        if(a[hmm[x]]<a[hmm[x]-1])ans--;
        if(a[hmm[x]+1]<a[hmm[x]])ans--;
        if(hmm[y]-1!=hmm[x])if(a[hmm[y]]<a[hmm[y]-1])ans--;
        if(hmm[y]+1!=hmm[x])if(a[hmm[y]+1]<a[hmm[y]])ans--;

        swap(a[hmm[x]],a[hmm[y]]);
        swap(hmm[x],hmm[y]);

        if(hmm[x]-1!=hmm[y])if(a[hmm[x]]<a[hmm[x]-1])ans++;
        if(hmm[x]+1!=hmm[y])if(a[hmm[x]+1]<a[hmm[x]])ans++;
        if(a[hmm[y]]<a[hmm[y]-1])ans++;
        if(a[hmm[y]+1]<a[hmm[y]])ans++;

        cout << ans << endl;
    }
}