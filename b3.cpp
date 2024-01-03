#include "utils.h"

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<int> a(m), b(n);
    for (int &ai : a)
        cin >> ai;
    for (int &bi : b)
        cin >> bi;

    b = mergeSort(b);

    int res = abs(a[0] + b[0]);

    for (int i = 0; i < m; i++)
    {
        int value = a[i];
        // a + b when a + b >= 0 => b >= -a -> find the first element in b that >= -a
        int l = lowerBound(b, -value);
        if (l < n)
            res = min(res, abs(value + b[l]));

        // -a -b when a + b < 0 => b < -a -> find the last element in b that < -a
        int r = lowerBound(b, -value) - 1;
        if (r >= 0)
            res = min(res, abs(value + b[r]));
    }

    cout << res << endl;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}

/*
Đề bài: Cho 2 dãy A, B. Tìm 2 phần tử a, b sao cho |a + b| là nhỏ nhất có thể

Ý tưởng: |a + b| = min(a + b với a >= -b, - a - b với a < -b)
    Sắp xếp mang B tăng dần
    Duyệt mảng A, với mỗi phần tử a, tìm phần tử b trong B sao cho |a + b| là nhỏ nhất có thể
    Dùng binary search để tìm phần tử b trong B
    Nếu a + b >= 0 thì tìm phần tử b đầu tiên trong B mà >= -a
    Nếu a + b < 0 thì tìm phần tử b cuối cùng trong B mà < -a
    So sánh |a + b| với kết quả hiện tại

m là số lượng phần tử của mảng A
n là số lượng phần tử của mảng B
Độ phức tạp: O(n*logn) + O(m * logn) 

Không gian: O(1) do không cần tạo thêm mảng
*/