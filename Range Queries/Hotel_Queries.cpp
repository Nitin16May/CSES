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
//////*************Nitin1605***************//////
template <typename treetype>class segtree
{
    public:
    treetype operation(treetype operand1,treetype operand2)
    {
        return max(operand1,operand2);
    }
    void merge(int pos)
    {
        if(pos<=N-1)nodes[pos]=operation(nodes[2*pos],nodes[2*pos+1]);
    }
    vector<treetype> nodes;
    int N,n;
    treetype default_value;
    segtree(int si,treetype temp)
    {
        n=si;N=n;
        if(N & (N - 1))N=0x8000000000000000 >> (__builtin_clzll(N) - 1);
        if(N==1)N=2;
        nodes.assign(N*2+5,temp);
        default_value=temp;
    };
    void input()
    {
        f(i,1,n)cin >> nodes[N+i-1];
        fr(i,N-1,1)merge(i);
    }
    int allocroom(int x,int p)
    {
        int ans=0;
        if(p>=N){ans=p-N+1;nodes[p]-=x;}
        else if(nodes[2*p]>=x){ans=allocroom(x,2*p);merge(p);}
        else if(nodes[2*p+1]>=x){ans=allocroom(x,2*p+1);merge(p);}
        return ans;
    }
    void printtree()
    {
        int NextTwo=1,count=0;
        f(i,1,N+N-1)
        {
            cout << nodes[i] << " ";
            count++;
            if(count==NextTwo)
            {
                cout << endl;
                NextTwo=NextTwo*2;count=0;
            }
        }
        cout << endl;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    int n,q;
    cin >> n >> q;
    segtree<int> a(n,INT_MIN);
    a.input();
    f(i,1,q)
    {
        cin >> n;
        cout << a.allocroom(n,1) << " ";
    }
}