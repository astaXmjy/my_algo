#include <bits/stdc++.h>
using namespace std;

bool compare_boxes(vector<int> b1, vector<int> b2)
{
    return b1[2] > b2[2];
}

bool can_place(vector<int> a, vector<int> b)
{
    if (a[0] > b[0] and a[1] > b[1] and a[2] > b[2])
        return true;
    return false;
}

int max_height_stack_box(vector<vector<int>> v)
{
    sort(v.begin(), v.end(), compare_boxes);
    int ans = 0;
    int n = v.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i] = v[i][2];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (can_place(v[j], v[i]))
            {
                int current_height = v[i][2];

                if (dp[j] + current_height > dp[i])
                {
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> boxes = {
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5},
    };

    cout << max_height_stack_box(boxes) << endl;

    return 0;
}
