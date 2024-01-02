#include "utils.h"

// Gọi gn là số lượng các cặp p,q khác nhau sao cho p+q=2×n và p,q là nguyên tố. Hai cặp được gọi là khác nhau nếu 1 trong 2 số tham gia vào cặp này và không tham gia vào cặp còn lại. Cho số nguyên n. Hãy tính giá trị biểu thức: fn=g2+g3+…+gn.
// sang nguyen to

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

    // 3 5 7 11 13 17
    // n = 4

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