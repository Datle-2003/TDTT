#include "utils.h"

int main()
{
    int n;
    cin >> n;
    const int k = 2;
    for (int mask = 1; mask <= int(pow(k, 9)); mask++) // O(2^9)
    {
        int temp = mask;
        vector<int> digits; // tối đa 9 phần tử
        while (temp > 0)
        {
            digits.push_back(temp % k);
            temp /= k;
        }
        reverse(digits.begin(), digits.end());
        int m = 0;
        for (int p : digits)
        {
            m = m * 10 + p;
        }
        if (m % n == 0)
        {
            cout << m << endl;
            return 0;
        }
    }
}

/*
Đề bài: Cho số nguyên dương n, tìm số nguyên dương m(chỉ chứa 0, 1) nhỏ nhất sao cho m chia hết cho n
Ý tưởng: Các số từ 1->2^9 ở dạng nhị phân chỉ chứa 0, 1 và có tối đa 9 chữ số
        Vì vậy, ta có thể duyệt qua các số từ 1->2^9, lấy dạng nhị phân của nó và chuyển sang hệ thập phân, kiểm tra xem số đó có chia hết cho n không
        Nếu có thì in ra và kết thúc chương trình
        Nếu không thì tiếp tục duyệt
Thời gian: O(2^9 * (9 + 9 + 9))
Không gian: O(1)

*/