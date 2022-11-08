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
    multimap<int,pair<int,int>> e;
    vector<int> a(n);
    f(i,0,n-1)cin >> a[i];
    f(i,0,n-1)
    {
        f(j,i+1,n-1)e.insert({a[i]+a[j],{i,j}});
    }
    f(i,0,n-1)
    {
        f(j,0,n-1)
        {
            if(i==j || s-a[i]-a[j]<0)continue;
            auto range = e.equal_range(s-a[i]-a[j]);
            for (auto it = range.first; it != range.second; ++it)
            {
                if(it->second.first!=i && it->second.second!=i && it->second.first!=j && it->second.second!=j)
                {
                    cout << i+1 << " " << j+1 << " " << it->second.first+1 << " " << it->second.second+1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}