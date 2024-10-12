#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &coins, int l, int h, int x)
{

    int change = INT_MIN;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (coins[mid] <= x)
        {
            change = max(change, coins[mid]);
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return change;
}

int main(int argc, char const *argv[])
{
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    int q;
    cin >> q;

    while (q--)
    {
        int coin_change;
        cin >> coin_change;

        int low = 0;
        int high = coins.size() - 1;

        int no_req_change = 0;

        while (coin_change)
        {
            no_req_change++;
            coin_change = coin_change - binary_search(coins, low, high, coin_change);
        }

        cout << no_req_change << endl;
    }

    return 0;
}
