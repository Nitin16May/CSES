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
void input()
{
    N=n;
    if(N & (N - 1))N=0x8000000000000000 >> (__builtin_clzll(N) - 1);
    a=vector<int>(N*2,0);
    f(i,1,n)cin >> a[N+i-1];
    fr(i,N-1,1)a[i]=(a[2*i]+a[2*i+1]);
}
//p=1,lol=N,s,e,ps=1,pe=n
int query(int p,int lol,int s,int e,int ps,int pe)
{
    if(pe<=e && ps>=s)return a[p];
    if(pe<s || ps>e)return 0;
    int m=ps+lol/2-1;
    return (query(p*2,lol/2,s,e,ps,m)+query(p*2+1,lol/2,s,e,m+1,pe));
}
//p=1,lol=N,ps=1,pe=n,d=destination,x=value
int pointupdate(int p,int lol,int ps,int pe,int d,int x)
{
    if(pe<d || ps>d)return a[p];
    if(lol==1)return a[p]=x;
    else return a[p]=(pointupdate(p*2,lol/2,ps,ps+lol/2-1,d,x)+pointupdate(p*2+1,lol/2,ps+lol/2,pe,d,x));
}
void printtree()
{
    int NextTwo=1,count=0;
    f(i,1,N+N-1)
    {
        cout << a[i] << " ";
        count++;
        if(count==NextTwo)
        {
            cout << endl;
            NextTwo=NextTwo*2;count=0;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int x,q,s,e;
    cin >> x >> q;n=x;
    input();
    while(q--)
    {
        cin >> x >> s >> e;
        if(x==1)pointupdate(1,N,1,n,s,e);
        else cout << query(1,N,s,e,1,n) << endl;
    }
}