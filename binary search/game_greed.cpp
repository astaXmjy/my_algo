#include<bits/stdc++.h>
using namespace std;

bool divideAmongK(vector<int> a,int n,int k,int diff){
    int partitions = 0;
    int current_friend = 0;
    for (int i = 0; i < n; i++)
    {
            if(current_friend+a[i]>=diff){
                partitions += 1;
                current_friend = 0;
                if(partitions==k)
                    return true;
            }
            else{
                current_friend += a[i];
            }
    }

    return false;
}

int k_partition(vector<int> a,int n,int k){
    int s = 0;
    int e = 0;
    for (int i = 0; i < n;i++){
        e += a[i];
    }

    int ans = -1;

    while (s<=e)
    {
        int mid = (s + e) / 2;

        bool isPossible = divideAmongK(a, n, k, mid);

        if(isPossible){
            s = mid + 1;
            ans = mid;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    int k = 3;
    vector<int> coins{1, 2, 3, 4};
    int n = coins.size();

    cout << k_partition(coins, n, k) << endl;
    return 0;
}
