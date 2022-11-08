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
    int n;
    cin >> n;
    int rooms=0;
    vector<array<int,3>> a(n);
    vector<int> ans(n,0);
    f(i,0,n-1)cin >> a[i][0] >> a[i][1],a[i][2]=i;
    sort(all(a));
    set<array<int,2>> wl;
    f(i,0,n-1)
    {
        if(wl.size()==0)
        {
            rooms++;
            ans[a[i][2]]=rooms;
            wl.insert({a[i][1],rooms});
            continue;
        }
        array<int,2> lol=(*wl.begin());
        if(lol[0]<a[i][0])
        {
            wl.erase(wl.begin());
            ans[a[i][2]]=lol[1];
            wl.insert({a[i][1],lol[1]});
        }
        else
        {
            rooms++;
            ans[a[i][2]]=rooms;
            wl.insert({a[i][1],rooms});
        }
    }
    cout << rooms << endl;
    f(i,0,n-1)cout << ans[i] << " ";
}