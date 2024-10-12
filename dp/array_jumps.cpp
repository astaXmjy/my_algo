#include <bits/stdc++.h>
using namespace std;

int jumps(vector<int> &v, int i,vector<int>&dp)
{
    if (i == v.size() - 1)
    {
        return 0;
    }
    if (i >= v.size())
    {
        return INT_MAX;
    }
    if(dp[i]!=0){
        return dp[i];
    }
    int ans = INT_MAX;

    for (int j = 1; j <= v[i]; j++)
    {
        int subporb = jumps(v, i + j,dp);
        if(subporb!=INT_MAX){
            ans = min(ans, subporb + 1);
        }
    }

    return dp[i] = ans;
}

int bottomUp(vector<int>&v){
    int n = v.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j<i;j++){
             if(i<=j+v[j] and dp[j]!=INT_MAX){
                 dp[i] = min(dp[i], dp[j] + 1);
                 break;
             }
        }
    }

    return dp[n - 1];
}

int main(int argc, char const *argv[])
{
    vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    vector<int> dp(arr.size(), 0);

    cout << jumps(arr, 0,dp) <<" "<<bottomUp(arr)<<endl;
    return 0;
}
