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
    vector<int> d(1e6+1,0),c(1e6+1,0);
    d[1]=1;c[1]=1;
    f(i,2,1e6)
    {
        d[i]=(4*d[i-1]+c[i-1])%1000000007;
        c[i]=(2*c[i-1]+d[i-1])%1000000007;
    }
    int TESTCASES=1,n;
    cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        cin >> n;
        cout << (d[n]+c[n])%1000000007 << endl;
    }
}