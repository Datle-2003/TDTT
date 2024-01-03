#include "utils.h"

void solve()
{
    int n;
    cin >> n;

    int size = 2 * n + 1;

    vector<bool> isPrime(size, true);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 2 * n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= 2 * n; j += i)
                isPrime[j] = false;

    vector<int> primes;
    for (int i = 3; i <= 2 * n; i++)
        if (isPrime[i])
            primes.push_back(i);
    int ans = 1; // g2
    for (int i = 0; i < primes.size(); i++)
    {
        int p = primes[i];
        int q = 2 * n - p; // phần tử lớn nhất có thể hợp q -> số chẵn <= 2 * n
        int l = i, r = primes.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (primes[mid] <= q)
                l = mid + 1;
            else
                r = mid - 1;
        }
        int cnt = r - i + 1;
        ans += cnt;
    }

    cout << ans << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();

    return 0;
}






/*

Đề bài: g(n) = số lượng (p, q) thỏa p + q = 2 * n và p, q là số nguyên tố
        tìm f(n) = g(2) + g(3) + ... + g(n)
    
Ý tưởng: Tìm các số nguyên tố từ 2 đến 2 * n
        Tạo được một mảng primes[] chứa các số nguyên tố từ 2 đến 2 * n
        Duyệt 1 vòng lặp, mới mỗi số nguyên tố p, tìm số nguyên tố lớn nhất q sao cho p + q = 2 * n
        Khi đó, số lượng cặp (p, q) thỏa mãn là số lượng số nguyên tố trong đoạn [p, q]
        do primes[] đã được sắp xếp tăng dần, ta có thể dùng binary search để tìm số lượng số nguyên tố trong đoạn [p, q]
        Sau đó, cộng số lượng số nguyên tố trong đoạn [p, q] vào kết quả

Độ phức tạp: O(nlogn) + O(n) + O((n / logn) * log(n / logn))
            -> O(nlogn) + O(n)

Không gian: O(n) + O(n/logn)
*/