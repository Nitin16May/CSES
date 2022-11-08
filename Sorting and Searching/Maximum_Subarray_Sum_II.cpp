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
    int n,l,r,c=0,d=0;
    cin>>n>>l>>r;
    vector<int> a(n+1,0);
    f(i,1,n)cin >> a[i],a[i]+=a[i-1];
    int ans=LLONG_MIN;
    multiset<pair<int,int>> s;
    f(i,l,n)
    {
        s.insert({a[d],d});d++;
        if(s.size()>r-l+1){s.erase({a[c],c});c++;}
        if(i>=r)ans=max(ans,a[i]-a[i-r]);
        ans=max(ans,a[i]-a[i-l]);
        ans=max(ans,a[i]-s.begin()->first);
    }
    cout << ans;
}