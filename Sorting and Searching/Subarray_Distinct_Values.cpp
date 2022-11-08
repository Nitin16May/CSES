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
//////*************Nitin1605***************//////

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,k,x=0,dis=0,ans=0;
    cin >> n >> k;
    map<int,int> a;
    vector<int> v(n);
    f(i,0,n-1)cin >> v[i];
    f(i,0,n-1)
    {
        while(x<n && (dis<k || a[v[x]]>0))
        {
            a[v[x]]++;
            if(a[v[x++]]==1)dis++;
        }
        ans+=x-i;
        a[v[i]]--;
        if(a[v[i]]==0)dis--;
    }
    cout << ans << endl;
}