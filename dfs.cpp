vector<ll> v[200005];
ll vis[200005];

void dfs(ll n)
{
    if(vis[n] == 0)
    {
        vis[n] = 1;
        for(ll i = 0;i < v[n].size();i++)
        {
            if(vis[v[n][i]] == 0)
            {
                dfs(v[n][i]);
            }
        }
    }
}
