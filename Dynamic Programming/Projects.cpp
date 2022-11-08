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
    int n,days=1,x=0;
    cin>>n;
    vector<array<int,3>> a(n);
    map<int,int> compress;
    f(i,0,n-1)
    {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
        compress[a[i][1]]=0;
        compress[a[i][0]]=0;
    }
    for(auto &i:compress)i.second=days++;
    f(i,0,n-1)
    {
        a[i][0]=compress[a[i][0]];
        a[i][1]=compress[a[i][1]];
    }
    sort(all(a));
    vector<int> dp(days+1,0);
    f(i,1,days)
    {
        dp[i]=dp[i-1];
        if(x==n)break;
        if(i<a[x][0])continue;
        while(i>=a[x][0])
        {
            dp[i]=max(dp[i],dp[a[x][1]-1]+a[x][2]);x++;
            if(x==n)break;
        }
    }
    cout << dp[days];
}