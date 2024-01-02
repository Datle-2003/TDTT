#include "utils.h"
// Cho hai dãy số nguyên 𝐴 = a1,a2,…, am và 𝐵 = (b1,b2,…, bn) hãy tìm một phần tử ai trong dãy 𝐴 và một phần tử bj trong dãy 𝐵 có |ai+bj| là nhỏ nhất có thể (1 ≤ 𝑖 ≤ 𝑚; 1 ≤ 𝑗 ≤ 𝑛).
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