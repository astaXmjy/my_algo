#include <bits/stdc++.h>
using namespace std;

vector<int> calc_subarray(vector<int> &arr, int n, int f)
{
    vector<int> res;

    for (int i = 0; i < (1 << n); i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                s += arr[j + f];
            }
        }
        res.push_back(s);
    }

    return res;
}

void print_vector(vector<int> arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
}

int main(int argc, char const *argv[])
{
    // for this example we should only take positive integers
    // so when you give a negative value our while loop exist consider this as the process of stop giving input to vector.

    int subSum = 11;

    vector<int> arr{3, 34, 4, 12, 5, 20};

    vector<int> x = calc_subarray(arr, arr.size() / 2, 0);
    vector<int> y = calc_subarray(arr, arr.size() / 2, arr.size()-arr.size() / 2);

    sort(y.begin(), y.end());

    // print_vector(x);
    // cout << endl;
    // print_vector(y);

    int ans = INT_MIN;

    int y_size = 1 << (arr.size() - arr.size() / 2);

    for (int i = 0; i < (1 << (arr.size() / 2)); i++)
    {
       if(x[i]<=subSum){
           auto p = lower_bound(y.begin(), y.end(), subSum - x[i]);
           if(p==y.end() or *p!=(subSum-x[i])){
               p--;
           }
           ans = max(ans, x[i]+(*p));
       }

    }

    cout << ans;

    return 0;
}
