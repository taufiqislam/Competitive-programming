#pragma GCC Optimize ("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll int
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



vector<pair<ll, pair<ll,ll>> > adj[1005];
ll n,b;

const ll INF = 1000000000;
ll dis[1005];
ll path[1005];
ll vis[1005][105];

ll dijkstra(ll s) {
    priority_queue<pair<ll,pair<ll,ll> > > pq;
    ll i,j;
    for(i = 0;i <= n+1;i++)
    {
        dis[i] = INF;
        path[i] = INF;
    }
    dis[s] = 0;
    path[s] = 0;
    pq.push(make_pair(0,make_pair(0,s)));
    while(!pq.empty())
    {
        pair<ll,pair<ll,ll> > p = pq.top();
        pq.pop();
        ll u = p.ss.ss;
        ll weight = p.ff*(-1);
        ll len = p.ss.ff;
        //cout << u << " " << weight << " t " << len << N;
        if(u == n+1) return weight;
        if(((dis[u] < weight) && (path[u] <= len)) || ((dis[u] == weight) && (path[u] < len)))
        {
            continue;
        }
        if(vis[u][len]) continue;
        vis[u][len] = 1;
        for(i = 0;i < adj[u].size();i++)
        {
            pair<ll,pair<ll,ll>> edge = adj[u][i];
            ll to = edge.first;
            ll weight3 = edge.ss.ff * edge.ss.ss;
            ll len3 = edge.ss.ss;
            //cout << to << " " << weight3 << " x " << len3 << N;
            if(len+len3 > b)
            {
                continue;
            }
            if(dis[to] > (weight+weight3))
            {
                dis[to] = weight+weight3;
                path[to] = len+len3;
                pq.push(make_pair(dis[to]*(-1),make_pair(path[to],to)));
            }
            else if((dis[to] == weight+weight3) && (len+len3 < path[to]))
            {
                path[to] = len+len3;
                pq.push(make_pair(dis[to]*(-1),make_pair(path[to],to)));
            }
            else if(len+len3 < path[to])
            {
                pq.push(make_pair((weight+weight3)*(-1),make_pair(len+len3,to)));
            }
        }
        //cout << N;
    }
    return 1e9;
}



int main()
{
    fastIO();
    ll t = 1,it;
    for(it = 1;it <= t;it++)
    {
        ll m,q,i,j,k,s = 0,x,y,c = 0,d = 0,f = 0,xs,ys,xd,yd,c0,l;
        double dx,dy;

        cin >> xs >> ys;
        cin >> xd >> yd;
        cin >> b;
        cin >> c0;
        cin >> m;
        vector<ll> cost;
        for(i = 0;i < m;i++)
        {
            cin >> c;
            cost.pb(c);
        }
        cin >> n;

        vector<pair<ll,ll>> vp;
        vector<pair<ll,ll>> g[n+5];
        for(i = 0;i < n;i++)
        {
            cin >> x >> y >> l;
            vp.pb(make_pair(x,y));
            for(j = 0;j < l;j++)
            {
                cin >> c >> d;
                g[i].pb(make_pair(c,d-1));
            }
        }
        dx = sqrt((xs - xd)*(xs - xd)  +  (ys - yd)*(ys - yd));
        d = ceil(dx);
        adj[0].pb(make_pair(n+1,make_pair(c0,d)));
        for(i = 0;i < n;i++)
        {
            dx = sqrt((vp[i].ff - xs)*(vp[i].ff - xs)  +  (vp[i].ss - ys)*(vp[i].ss - ys));
            d = ceil(dx);
            adj[0].pb(make_pair(i+1,make_pair(c0,d)));

            for(j = 0;j < g[i].size();j++)
            {
                dx = sqrt((vp[i].ff - vp[g[i][j].ff].ff)*(vp[i].ff - vp[g[i][j].ff].ff)  +  (vp[i].ss - vp[g[i][j].ff].ss)*(vp[i].ss - vp[g[i][j].ff].ss));
                d = ceil(dx);
                adj[i+1].pb(make_pair(g[i][j].ff+1,make_pair(cost[g[i][j].ss],d)));
                adj[g[i][j].ff+1].pb(make_pair(i+1,make_pair(cost[g[i][j].ss],d)));
            }
            dx = sqrt((vp[i].ff - xd)*(vp[i].ff - xd)  +  (vp[i].ss - yd)*(vp[i].ss - yd));
            d = ceil(dx);
            adj[i+1].pb(make_pair(n+1,make_pair(c0,d)));
        }
        s = dijkstra(0);
        if(path[n+1] > b)
        {
            dis[n+1] = -1;
        }
        cout << dis[n+1] << N;
    }
    return 0;
}





