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

//    ███╗   ██╗██╗████████╗██╗███╗   ██╗ ██╗ ██████╗  ██████╗ ███████╗  
//    ████╗  ██║██║╚══██╔══╝██║████╗  ██║███║██╔════╝ ██╔═████╗██╔════╝  
//    ██╔██╗ ██║██║   ██║   ██║██╔██╗ ██║╚██║███████╗ ██║██╔██║███████╗  
//    ██║╚██╗██║██║   ██║   ██║██║╚██╗██║ ██║██╔═══██╗████╔╝██║╚════██║  
//    ██║ ╚████║██║   ██║   ██║██║ ╚████║ ██║╚██████╔╝╚██████╔╝███████║  
//    ╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝  

void boom(vector<string> &s,int i,int j,int n,int m)
{
    if(i==-1 || i==n || j==-1 || j==m)return;
    if(s[i][j]=='#')return;
    s[i][j]='#';
    boom(s,i-1,j,n,m);boom(s,i+1,j,n,m);
    boom(s,i,j-1,n,m);boom(s,i,j+1,n,m);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,m,ans=0;
    cin>>n>>m;
    vector<string> s(n);
    f(i,0,n-1)
    {
        cin >> s[i];
    }
    f(i,0,n-1)
    {
        f(j,0,m-1)
        {
            if(s[i][j]=='#')continue;
            ans++;
            boom(s,i,j,n,m);
        }
    }
    cout << ans << endl;
}
