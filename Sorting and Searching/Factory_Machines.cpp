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
int n,k,x;
vector<int> a;
bool easypeasy(int lol)
{
    x=0;
    f(i,0,n-1)
    {
        x=x+(lol/a[i]);
        if(x>=k)return true;
    }
    return false;
}
int FirstTrue() 
{
    int lo=1,hi=1e18+1;
    while (lo < hi) 
    {
        int mid=lo+(hi-lo)/2;
        if (easypeasy(mid))hi=mid;
        else lo=mid+1;
    }
    return lo;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    cin >> n >> k;
    f(i,1,n)
    {
        cin >> x;
        a.push_back(x);
    }
    cout << FirstTrue();
}