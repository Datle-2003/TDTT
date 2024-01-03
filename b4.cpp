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

/*
Đề bài: Đếm số cặp nghịch thế trong một dãy số
Ý tưởng: Chia mảng ban đầu thành 2 mảng con, thực hiện đếm số cặp nghịch thế trong mảng con bên trái, mảng con bên phải, và đếm số cặp nghịch thế giữa 2 mảng con
Gọi số phần tử mảng bên trái là k, số phần tử mảng con bên phải là l, nếu đếm thông thường sẽ có độ phức tạp là O(k*l)
Tuy nhiên, nếu mảng bên trái và mảng bên phải đã được sắp xếp thì ta có thể đếm số cặp nghịch thế trong O(k + l)
Do đó, ta có thể sử dụng merge sort để đếm
Giả sử ta đang xét 2 phần tử a[i] và a[j] trong 2 mảng con bên trái và bên phải, nếu a[i] > a[j] thì ta có thể chắc chắn rằng a[i + 1] > a[j], a[i + 2] > a[j], ..., a[k - 1] > a[j]

Độ phức tạp: O(n * logn)
Mỗi lần, chia mảng thành 2 mảng con (bằng hoặc gần bằng nhau) -> tốn logn thao tác -> O(logn)
Mỗi lần, đếm số cặp nghịch thế trong 2 mảng con -> O(k + l) -> O(n)
Không gian: O(n)
*/