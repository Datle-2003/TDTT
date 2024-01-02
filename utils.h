#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <numeric>
#include <functional>
#include <iomanip>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <complex>
#include <climits>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cfloat>
#include <cstdarg>
#include <numbers>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for (int i = 0; i < (n); ++i)

vector<int> mergeSort(vector<int> &a)
{
    if (a.size() == 1)
        return a;
    int mid = a.size() / 2;

    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> res;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            res.push_back(left[i++]);
        else
            res.push_back(right[j++]);
    }

    while (i < left.size())
        res.push_back(left[i++]);

    while (j < right.size())
        res.push_back(right[j++]);

    return res;
}

int upperBound(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int lowerBound(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l; 

}


#endif