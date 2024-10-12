#include <bits/stdc++.h>
using namespace std;

int frog(vector<int> &height, int n)
{
    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = abs(height[0] - height[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(height[i - 1] - height[i]), dp[i - 2] + abs(height[i - 2] - height[i]));
    }

    return dp[n - 1];
}

int main(int argc, char const *argv[])
{
    vector<int> height{10, 30, 40, 20};

    cout << frog(height, height.size()) << endl;

    return 0;
}
