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

ll seg[4 * 200005];

ll lazy[4*200005];

void prop(ll low,ll high,ll ind)
{
    if(low != high)
    {
        lazy[2*ind] = lazy[ind];
        lazy[2*ind+1] = lazy[ind];
    }
    ll x = (high - low + 1);
    seg[ind] = x * lazy[ind];
    lazy[ind] = 0;
    return;
}

void build(ll ara[],ll ind,ll low,ll high)
{
    if(low == high)
    {
        seg[ind] = ara[low-1];
        return;
    }
    ll mid = (low + high) / 2;
    build(ara,2*ind,low,mid);
    build(ara,2*ind+1,mid+1,high);
    seg[ind] = seg[2*ind] + seg[2*ind+1];
    return;
}

ll lazyquery(ll ind,ll low,ll high,ll l,ll r)
{

    if((lazy[ind] != 0))
    {
        prop(low,high,ind);
    }
    if((r < low) || (l > high))
    {
        return 0;
    }
    if((low >= l) && (high <= r))
    {
        return seg[ind];
    }

    ll mid = (low + high) / 2;
    return lazyquery(2*ind,low,mid,l,r) + lazyquery(2*ind+1,mid+1,high,l,r);
}

void rangeupdate(ll ind,ll low,ll high,ll l,ll r,ll v)
{
    //cout << low << " " << high << " " << l << " " << r << N;
    //cout << lazy[ind].ff << " " << lazy[ind].ss << N;
    if((lazy[ind] != 0))
    {
        prop(low,high,ind);
    }
    if((r < low) || (l > high))
    {
        return;
    }
    if((low >= l) && (high <= r))
    {

        lazy[ind] = v;
        prop(low,high,ind);
        return;
    }

    ll mid = (low + high) / 2;
    rangeupdate(2*ind,low,mid,l,r,v);
    rangeupdate(2*ind+1,mid+1,high,l,r,v);
    seg[ind] = seg[2*ind] + seg[2*ind+1];
}


int main()
{
    //fastIO();
    ll t = 1,it;
    for(it = 1;it <= t;it++)
    {
        ll n,q,i,j,k,s = 0,x,y,c = 0,d,a,b;
        cin >> n >> q;
        ll ara[n];
        for(i = 0;i < n;i++)
        {
            cin >> ara[i];
        }
        build(ara,1,1,n);
        for(i = 0;i < q;i++)
        {
            cin >> c >> a >> b;
            if(c == 1)
            {
                rangeupdate(1,1,n,a,a,b);
            }
            else
            {
                cout << lazyquery(1,1,n,a,b) << N;
            }
        }
    }
    return 0;
}
