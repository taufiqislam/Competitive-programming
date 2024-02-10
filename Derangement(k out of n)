#pragma GCC Optimize ("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define N '\n'
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()
#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

const ll mod = 1e9+7;
ll fact[2005];
ll deran[2005];

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

long long dea(int n, int k) {
  long long ans = fact[n];
  for (int i = 1; i <= k; ++i) {
    ans -= ((i & 1)? 1 : -1) * (ncr(k, i) * fact[n - i]) % mod;
    ans = (ans + mod) % mod;
  }
  return ans;
}


int main()
{
    fastIO();
    ll t = 1,it;
    fact[0] = 1;
    for(it = 1;it <= 2000;it++)
    {
        fact[it] = (it * fact[it-1]) % mod;
    }
    cin >> t;
    for(it = 1;it <= t;it++)
    {
        ll n,m,q,i,j,k,s = 0,x,y,c = 0,d = 0,f = 0;
        cin >> n >> m >> k;
        s = (ncr(m,k) * dea(n-k,m-k)) % mod;
        cout << "Case " << it << ": " << s << N;
    }
    return 0;
}




