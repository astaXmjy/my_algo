#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> dis, int subset, int city, int n)
{
    if (subset == (1 << n) - 1)
    {
        return dis[city][0];
    }
    int ans=INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (subset & (1 << i) == 0)
        {
            int temp = dis[city][i] + tsp(dis, subset|(1 << i), i, n);
            ans = min(ans, temp);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> dis{
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}};

    cout << tsp(dis, 1, 0, 4);
    return 0;
}
