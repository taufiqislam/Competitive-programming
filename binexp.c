const ll mod = 1e9+7;
ll fact[2000005];

ll binexp(ll a,ll b)
{
    if(b == 0)
    {
        return 1;
    }
    ll result = binexp(a,b/2) % mod;
    result = (result * result) % mod;
    if(b % 2 == 1)
    {
        result = (result * a) % mod;
    }
    return result % mod;
}

ll ncr(ll n,ll r)
{
    ll x = (fact[n] * binexp(fact[n-r],mod-2)) % mod;
    return (x * binexp(fact[r],mod-2)) % mod;
}

