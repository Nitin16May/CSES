#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long int
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define llceil(a,b) ceil(((double)a)/((double)b))
#define llfloor(a,b) floor(((double)a)/((double)b))
#define vec vector<ll>
#define dvec vector<vector<ll>>
//////*************Nitin1605***************//////
template <int mod> struct ModInt
{
    int x;

    ModInt() : x(0)
    {
    }

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)
    {
    }

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p)
    {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const
    {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt &p) const
    {
        return ModInt(*this) += p;
    }

    ModInt operator-(const ModInt &p) const
    {
        return ModInt(*this) -= p;
    }

    ModInt operator*(const ModInt &p) const
    {
        return ModInt(*this) *= p;
    }

    ModInt operator/(const ModInt &p) const
    {
        return ModInt(*this) /= p;
    }

    bool operator==(const ModInt &p) const
    {
        return x == p.x;
    }

    bool operator!=(const ModInt &p) const
    {
        return x != p.x;
    }

    ModInt inverse() const
    {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    int get() const
    {
        return x;
    }

    static constexpr int get_mod()
    {
        return mod;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    ll n,sum;
    cin>>n;sum=(n*(n+1))/2;
    if(sum%2==1){cout << 0; return 0;}
    sum=sum/2;
    vector<vector<ModInt<1000000007>>> dp(n+1,vector<ModInt<1000000007>> (sum+1,0));
    f(i,0,n)dp[i][0]=1;
    f(i,1,n)
    {
        f(j,1,sum)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=i)dp[i][j]+=dp[i-1][j-i];
        }
    }
    cout << dp[n][sum]/2;
}