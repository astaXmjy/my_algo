#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int v[N];
bool cycle = false;

void dfs(int cur, int par)
{
    cout << cur << '\n';
    v[cur] = 1;
    for (auto x : gr[cur])
    {
        if (!v[x])
        {
            dfs(x, cur);
        }
        else if (x != par)
        {
            cycle = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            dfs(i, 0);
        }
    }

    if (cycle)
    {
        cout << "cycle is present in graph" << '\n';
    }
    else
    {
        cout << "no cycle is present in graph" << '\n';
    }

    return 0;
}
