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
int n,k;
vector<int> a;
bool lol(int mid)
{
    int ts=mid,s=1;
    f(i,0,n-1)
    {
        if(a[i]>mid)return false;
        if(a[i]<=ts)ts-=a[i];
        else {s++;ts=mid-a[i];}
    }
    return s<=k;
}
int FirstTrue(int lo,int hi,function<bool(int)> func) 
{
    hi++;
    while (lo < hi) 
    {
        int mid=lo+(hi-lo)/2;
        if (func(mid))hi=mid;
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
    int x,s=0;
    cin >> n >> k;
    f(i,0,n-1)
    {
        cin >> x;
        a.push_back(x);s+=x;
    }
    cout << FirstTrue(0,s,lol);
}