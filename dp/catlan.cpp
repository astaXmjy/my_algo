#include <bits/stdc++.h>
using namespace std;

int catlan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res += catlan(i) * catlan(n - i - 1);
    }

    return res;
}

int catlandp(int n)
{
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;

        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}
int catlan3(int n)
{
    int res = 1;

    // cout << res << " ";
    for (int i = 1; i < n + 1; i++)
    {
        res = (res * (4 * i - 2)) / (i + 1);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    cout << catlan(3) << endl;
    cout << catlan3(3) << endl;
    return 0;
}