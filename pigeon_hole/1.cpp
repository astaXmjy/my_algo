#include <bits/stdc++.h>
using namespace std;

int sum_subset_divisible_by_k(vector<int> &nums, int k)
{
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = nums[i] + nums[i - 1];
    }
    vector<int> ans;
    int size_ans = 0;
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] % k;
        if (s.find(nums[i]) != s.end() and nums[i] != 0)
        {
            return 1;
        }

        if (nums[i] == 0)
        {
            return 1;
        }
        s.insert(nums[i]);
    }
    return -1;
}

int main()
{
    
    return 0;
}
