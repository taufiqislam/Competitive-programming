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

vector<ll> v[10005];
vector<ll> g[10005];
ll vis[10005];
ll com[10005];

stack<ll> st;
ll x;
void dfs(ll n)
{
    if(vis[n] == 0)
    {

        vis[n] = 1;
        for(ll i = 0; i < v[n].size(); i++)
        {
            if(vis[v[n][i]] == 0)
            {
                dfs(v[n][i]);
            }
        }
        st.push(n);
    }
}

void dfs3(ll n)
{
    if(vis[n] == 0)
    {
        //cout << n << N;
        com[n] = x;
        vis[n] = 1;
        for(ll i = 0; i < g[n].size(); i++)
        {
            if(vis[g[n][i]] == 0)
            {
                dfs3(g[n][i]);
            }
        }
    }
}



int main()
{
    fastIO();
    ll t = 1,it;
    for(it = 1; it <= t; it++)
    {
        ll n,m,q,i,j,k,s = 0,y,c = 0,d = 0,f = 0;
        cin >> n >> m;
        vector<pair<ll,ll> > edge;
        for(i = 0; i < m; i++)
        {
            cin >> c >> d;

            v[c].pb(d);
            g[d].pb(c);
            edge.pb(make_pair(d,c));
        }
        for(i = 1; i <= n; i++)
        {
            dfs(i);
        }
        memset(vis,0,sizeof(vis));
        x = 1;
        while(!st.empty())
        {
            c = st.top();
            //cout << vis[c] << " v" << N;
            if(vis[c] == 0)
            {
                //cout << "t\n";
                dfs3(c);
                x++;
            }
            st.pop();
        }
        //cout << "x\n";
        //cout << x << N;
        ll indeg[x+5] = {};
        ll outdeg[x+5] = {};
        for(i = 0; i < m; i++)
        {
            c = edge[i].ff;
            d = edge[i].ss;
            if(com[c] != com[d])
            {
                indeg[com[d]]++;
                outdeg[com[c]]++;
            }
        }
//        for(i = 1; i <= n; i++)
//        {
//            cout << i << " " << com[i] << N;
//        }
        ll cnt1 = 0,cnt3 = 0;
        x--;
        if(x > 1)
        {
            for(i = 1; i <= x; i++)
            {
                //cout << i << " " << indeg[i] << " " << outdeg[i] << N;
                if(indeg[i] >= 1)
                {
                    cnt1++;
                }
                if(outdeg[i] >= 1)
                {
                    cnt3++;
                }
            }
            s = max(x-cnt1,x-cnt3);
        }
        else
        {
            s = 0;
        }
        cout << s << N;
    }
    return 0;
}





