#include <bits/stdc++.h>
using namespace std;

// Top Down
int countWays(int n, int k, int *dp)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != 0)
        return dp[n];
    int ans = 0;

    for (int i = 1; i <= k; i++)
    {
        ans += countWays(n - i, k, dp);
    }

    return dp[n] = ans;
}

// Bottom Up

int countWays(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int jump = 1; jump <= k; jump++)
        {
            if (i - jump >= 0)
            {
                dp[i] += dp[i - jump];
            }
        }
    }

    return dp[n];
}

int countWaysOptimize(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int dp[1000] = {0};
    cout << countWays(4, 3, dp) << " " << countWays(4, 3) << " " << countWaysOptimize(4, 3) << endl;

    return 0;
}
