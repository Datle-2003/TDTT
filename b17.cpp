#include "utils.h"

// Cho số nguyên dương n. Hãy tìm số nguyên dương m nhỏ nhất có không quá 9 chữ số thỏa m chỉ chứa các chữ số {0,1} và m là bội của n.
// Dữ liệu vào:
// Gồm một số nguyên dương nn≤100
// Kết quả:
// Gồm một số nguyên duy nhất là m

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