#include<bits/stdc++.h>
using namespace std;

int longest_inc_sub_seq(vector<int>&v){
    int ans = 1;

    int n = v.size();

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(v[j]<v[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{50, 4, 10, 8, 30, 100, 2,101,102};

    cout << longest_inc_sub_seq(arr) << endl;
    return 0;
}
