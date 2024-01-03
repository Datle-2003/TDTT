#include "utils.h"

void solve()
{
    string s;
    cin >> s;
    stringstream ss(s);
    vector<int> a;
    int num;
    char c;
    while (ss >> num)
    {
        a.push_back(num);
        if (!(ss >> c))
            break;
    }

    int n = a.size();
    int maxLeft = a[0], maxRight = a[n - 1];
    int l = 0, r = n - 1;
    int trappedWater = 0;
    // for each position, trapped water will base on the min of maxLeft and maxRight minus the height of the position
    // if the height of the position is greater than the min of maxLeft and maxRight, then the trapped water will be 0 and update the maxLeft or maxRight
    // if the height of the position is less than the min of maxLeft and maxRight, then the trapped water will be the min of maxLeft and maxRight minus the height of the position

    while (l <= r)
    {
        maxLeft = max(maxLeft, a[l]);
        maxRight = max(maxRight, a[r]);

        if (maxLeft < maxRight)
        {
            trappedWater += maxLeft - a[l] > 0 ? maxLeft - a[l] : 0;
            l++;
        }
        else
        {
            trappedWater += maxRight - a[r] > 0 ? maxRight - a[r] : 0;
            r--;
        }
    }

    cout << trappedWater << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}

/*
Đề bài: Cho một mảng các số nguyên dương, mỗi số nguyên dương là chiều cao của một cột nước.
Hãy tính tổng lượng nước có thể giữa các cột nước này.

Ý tưởng: Lượng nước ở mỗi vị trí sẽ phụ thuộc vào độ cao lớn nhất của cột nước bên trái và độ cao của cột nước bên phải
        Và nó bằng min(maxLeft, maxRight) - height[i], nếu nó > 0. Nếu <= 0 thì không có nước đọng ở vị trí đó
        Ta sẽ tạo 2 mảng maxLeft và maxRight để lưu độ cao lớn nhất bên trái và phải của từng vị trí
        Sau đó duyệt mảng, tính lượng nước đọng ở mỗi vị trí và cộng dồn vào biến kết quả

    Tuy nhiên, ta có thể cải tiến bằng cách không cần tạo 2 mảng maxLeft và maxRight mà chỉ cần 2 biến maxLeft và maxRight
    Vì ta chỉ cần min(maxLeft, maxRight) nên tả chỉ cần giá trị nhỏ hơn trong 2 biến maxLeft và maxRight
    giả sử biến nhỏ hơn là maxLeft, ta cập nhật maxLeft và tính lượng nước đọng ở vị trí đó
    nếu maxLeft > maxRight thì ta cập nhật maxRight và tính lượng nước đọng ở vị trí đó

    Độ phức tạp: O(n) do sử dụng 2 con trỏ l và r để duyệt mảng, mỗi con trỏ chỉ duyệt các phần tử 1 lần
    Không gian: O(1) do chỉ sử dụng 2 biến maxLeft và maxRight
*/