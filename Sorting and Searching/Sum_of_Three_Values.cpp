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
    int n,s;
    cin >> n >> s;
    vector<array<int,2>> a(n);
    f(i,0,n-1)cin >> a[i][0],a[i][1]=i+1;
    sort(all(a));
    f(i,0,n-1)
    {
        int x=i+1,y=n-1;
        while(x<y)
        {
            if(a[x][0]+a[y][0]==s-a[i][0])
            {
                cout << a[x][1] << " " << a[y][1] << " " <<  a[i][1] << endl;
                return 0;
            }
            else if(a[x][0]+a[y][0]<s-a[i][0])x++;
            else y--;
        }
    }
    cout << "IMPOSSIBLE";
}
