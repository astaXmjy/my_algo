#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&a,int s,int e){
    int pivot = a[e];
    int i = s - 1;

    for (int j = s; j < e; j++)
    {
        if(a[j]<pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

int quick_select(vector<int>&arr,int s,int e,int k){
    int p = partition(arr, s, e);
    if(p==k){
        return arr[p];
    }
    else if(k<p){
        return quick_select(arr, s, p - 1, k);
    }
    else
    return quick_select(arr, p + 1, e, k);
}

int main(int argc, char const *argv[])
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};   // 0 2 4 5 6 7 10
    int n = arr.size();

    cout << quick_select(arr, 0, n - 1, 4);
    return 0;
}
