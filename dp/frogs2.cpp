#include <bits/stdc++.h>
using namespace std;

void go(int index, int n, int k, vector<int> &heights, int dp[])
{
    cout << index << " ";
    for (int kk = 1; kk <= k and index - kk >= 0; kk++)
    {
        if (dp[index] == dp[index - kk] + abs(heights[index] - heights[index - kk]))
        {
            go(index - kk, n, k, heights, dp);
            return;
        }
    }
}

int frog2(vector<int> &heights, int k, int n)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = dp[0] + abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = INT_MAX;

        for (int kk = 1; kk <= k and i - kk >= 0; kk++)
        {
            // if (i - kk >= 0)
            dp[i] = min(dp[i], dp[i - kk] + abs(heights[i] - heights[i - kk]));
        }
    }

    go(n - 1, n, k, heights, dp);

    cout << endl;

    return dp[n - 1];
}

int main(int argc, char const *argv[])
{
    vector<int> heights{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};

    cout << frog2(heights, 4, heights.size());
    return 0;
}
