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
//////*************Nitin1605***************//////

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,q,aa,b,c,d;
    cin >> n >> q;
    dvec a(n+1,vec (n+1,0));
    f(i,1,n)
    {
        f(j,1,n)
        {
            char lol;
            cin >> lol;
            if(lol=='*')a[i][j]=1;
        }
    }
    f(i,1,n)
    {
        f(j,1,n)
        {
            a[i][j]+=a[i-1][j];
            a[i][j]+=a[i][j-1];
            a[i][j]-=a[i-1][j-1];
        }
    }
    while(q--)
    {
        cin >> aa >> b >> c >> d;
        cout << a[c][d]-a[c][b-1]-a[aa-1][d]+a[aa-1][b-1] << endl;
    }
}