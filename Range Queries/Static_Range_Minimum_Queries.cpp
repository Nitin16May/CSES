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
vector<int> a;int N,n;
void input(int n)
{
    N=n;
    if(N & (N - 1))N=0x8000000000000000 >> (__builtin_clzll(N) - 1);
    a=vector<int>(N*2+1,0);
    f(i,1,n)cin >> a[N+i-1];
    f(i,N+n,2*N)a[i]=1e10;
    fr(i,N-1,1)a[i]=min(a[2*i],a[2*i+1]);
}
int query(int p,int lol,int s,int e,int ps,int pe)
{
    if(pe<=e && ps>=s)return a[p];
    if(pe<s || ps>e)return 1e10;
    int m=ps+lol/2-1;
    return min(query(p*2,lol/2,s,e,ps,m),query(p*2+1,lol/2,s,e,m+1,pe));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,q,s,e;
    cin >> n >> q;
    input(n);
    while(q--){cin >> s >> e;cout << query(1,N,s,e,1,n) << endl;}
}