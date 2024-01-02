// Cho số n và một dãy gồm n số a1,a2,…an. Định nghĩa cặp số nghịch nhau là cặp hai số ai và aj trong dãy thỏa điều kiện i<j và ai>aj.
// Yêu cầu: Đếm số lượng các cặp số nghịch nhau trong dãy.

#include "utils.h"


vector<int> couting_inversion(vector<int> &a, int &count)
{
    if (a.size() == 1)
        return a;

    int mid = a.size() / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    left = couting_inversion(left, count);
    right = couting_inversion(right, count);

    vector<int> res;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] > right[j])
        {
            res.push_back(right[j++]);
            count += left.size() - i;
        }
        else
            res.push_back(left[i++]);
    }

    while (i < left.size())
        res.push_back(left[i++]);

    while (j < right.size())
        res.push_back(right[j++]);

    return res;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &ai : a)
    {
        cin >> ai;
    }

    int count = 0;
    couting_inversion(a, count);

    cout << count << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}