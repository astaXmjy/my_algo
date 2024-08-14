#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    vector<int> temp;
    int count = 0;
    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            count += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k++];
    }

    return count;
}

int inversion_count(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int c1 = inversion_count(arr, s, mid);
    int c2 = inversion_count(arr, mid + 1, e);
    int ci = merge(arr, s, e);
    return c1 + c2 + ci;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{4, 3, 2, 5, 1, 0};
    int s = 0;
    int e = arr.size() - 1;
    cout << (arr, s, e);

    return 0;
}
