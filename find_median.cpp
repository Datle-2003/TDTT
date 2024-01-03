#include <bits/stdc++.h>

using namespace std;
int find_median(vector<int> &arr, int l, int r, int medianPos){
    // partition
    int pivot = arr[l];
    int i = l + 1;
    int j = r;
    int pos;
    while(i <= j){
        while(arr[i] <= pivot)
            i++;
        while(arr[j] >= pivot)
            j--;
        if(i <= j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
        else if(j > l){
            pos = j;
            swap(arr[l], arr[j]);
        }
        else
            pos = l;
    }
    if(pos == medianPos)
        return arr[pos];
    else if(pos < medianPos){
        return find_median(arr, pos + 1, r, medianPos);
    }
    else
        return find_median(arr, l, pos - 1, medianPos);
}