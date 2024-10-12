#include <bits/stdc++.h>
using namespace std;

int no_of_activities(vector<pair<int,int>> &time)
{
    int ans = 0;

    int prev = 0;

    for (int i = 0; i < time.size(); i++)
    {
        if(time[i].first>=prev){
            ans++;
            prev = time[i].second;
        }

    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<pair<int, int>> time_intervel = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};

    sort(time_intervel.begin(), time_intervel.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    cout << no_of_activities(time_intervel) << endl;
    return 0;
}
