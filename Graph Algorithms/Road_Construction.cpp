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
#define pb push_back
//************Nitin1605************
class Graph 
{
    public:
    int v;
    vector<vector<int>> g;
    vector<int> father,sizee,lvl;
    void alloc(int x)
    {
        v=x;
        g=vector<vector<int>> (x+1);
        father=vector<int> (x+1);
        lvl=vector<int> (x+1,0);
        sizee=vector<int> (x+1,1);
    }
};
void solve(int m,Graph &a)
{
    f(i,1,a.v)a.father[i]=i;
    int x,y,z,tc=a.v,ms=1;
    f(i,1,m)
    {
        cin >> x >> y;
        int xf=x,yf=y;
        while(a.father[xf]!=xf)xf=a.father[xf];
        while(a.father[yf]!=yf)yf=a.father[yf];
        if(xf!=yf)
        {
            if(a.lvl[xf]==a.lvl[yf])a.lvl[xf]++;
            if(a.lvl[xf]<a.lvl[yf])swap(xf,yf);
            a.father[yf]=xf;tc--;
            a.sizee[xf]+=a.sizee[yf];
            ms=max(ms,a.sizee[xf]);
        }
        cout << tc << " " << ms << endl;
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
    Graph a;
    int n,m;
    cin >> n >> m;
    a.alloc(n);
    solve(m,a);
}
