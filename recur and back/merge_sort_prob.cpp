#include <bits/stdc++.h>
using namespace std;

int solve(int N, vector<int> A)
{

    // 1 2 5 9 14 14 17 18
    int ans = INT_MIN;

    for (int i = 0; i <N; i++)
    {
        for (int j = i; j < N; j++)
        {
           if(A[j]-A[i]<=10){
               ans = max(ans, j - i + 1);
           }
           else{
               break;
           }
        }

    }

    return ans;
}

int main()
{
    vector<int> A = {1,2,3,4,5,6,7,8,9,10,11,1,2,3,4,5};

   int out_ = solve(A.size(), A);
    cout << out_;
}