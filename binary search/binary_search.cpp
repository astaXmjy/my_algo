#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr, int val)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == val)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > val)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int upper_bound(vector<int> arr, int val)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == val)
        {
            ans = mid;
            s = mid + 1;
        }

        else if (arr[mid] > val)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}
  
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 6, 6, 6,6, 7, 8};
    int n;

    cin >>n;
     if(lower_bound(arr,n)==-1){
         cout << "kuch nhi mila bc" << endl;
     }
     else
     cout << "no. of element of " << n << " is equal to " << upper_bound(arr, n) - lower_bound(arr, n) + 1 << endl;

     return 0;
}
