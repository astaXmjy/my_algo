#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dfs(int u, int parent, vector<pair<int, int>> adj[], ll &ans, int N)
{
    int currentTreeSize = 1;
    for (auto p : adj[u])
    {
        int v = p.first;
        int wt = p.second;

        if(v==parent){
            continue;
        }

        int childTreeSize = dfs(v, u, adj, ans, N);
        int edgeContribution = 2 * min(childTreeSize, N - childTreeSize) * wt;
        ans += edgeContribution;
        currentTreeSize += childTreeSize;
    }

    return currentTreeSize;
}

int main()
{
    int test;
    cin >> test;

    int n, u, v, w;

    vector<pair<int, int>> adj[100005];

    int tc = 1;
    while (tc <= test)
    {
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }

        for (int i = 1; i <= n - 1; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        ll ans=0;
        dfs(1,-1,adj,ans,n);
        cout<< ans<<endl;
        tc++;
    }

    return 0;
}