#include "utils.h"

// Cho n đoạn liên tiếp, đoạn thứ i có chiều cao hi. Chiều cao chênh lệch giữa 2 đoạn liên tiếp không vượt quá 1 đơn vị. Ta cần đào sâu xuống càng sâu càng tốt. Ta dự định chi T đồng cho công việc này. Chi phí giảm chiều cao của một đoạn đi 1 đơn vị là 1 đồng.
//  Yêu cầu: Cho biết các chiều cao h1, h2, …, hn và chi phí T. Hãy xác định chiều cao thấp nhất (đào sâu nhất) mà ta có thể đào được với T đồng mà vẫn đảm bảo chênh lệch giữa 2 đoạn liên tiếp không quá 1 đơn vị.

int calc(int x)
{
    return x * (x + 1) / 2;
}

bool check(vector<int> &h, int T, long long mid, vector<int> &sum)
{
    long long minCost = 1e18; // minCost là chi phí nhỏ nhất để đào sâu xuống chiều cao mid
    int n = h.size();
    int l = 1, r = 1; // l là đoạn bắt đầu, r là đoạn kết thúc
    for (int i = 1; i <= n; i++) // duyệt qua các đoạn
    {
        r = max(r, i); // cập nhật r để đảm bảo đoạn [l, r] có chiều cao <= mid
        while (l < i && h[l + 1] <= (mid + (i - l))) // khi đoạn [l, r] có chiều cao <= mid, cập nhật l
            l++;
        while (r < n && h[r + 1] > (mid + (r - i + 1))) // khi đoạn [l, r] có chiều cao > mid, cập nhật r
            r++;
        long long curCost = -mid * (r - l + 1) + sum[r] - sum[l - 1] - calc(i - l) - calc(r - i);
        // curCost là chi phí để đào sâu xuống chiều cao mid của đoạn [l, r]
        // sum[r] - sum[l - 1] là tổng chiều cao của các đoạn từ l đến r
        // calc(i - l) là tổng chi phí để đào sâu xuống chiều cao mid của các đoạn từ l đến i
        // calc(r - i) là tổng chi phí để đào sâu xuống chiều cao mid của các đoạn từ i đến r
        minCost = min(minCost, curCost);
    }
    return minCost <= T;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, T;
    cin >> n >> T;

    vector<int> sum(n + 1, 0);

    vector<int> h(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        sum[i] = sum[i - 1] + h[i]; // sum[i] là tổng chiều cao của các đoạn từ 1 đến i
    }

    // using binary search
    long long low = -1e18;
    long long high = *min_element(h.begin(), h.end());
    // low là chiều cao thấp nhất có thể đào được
    // high là chiều cao cao nhất có thể đào được

    while (low <= high)
    {
        long long mid = (low + high) / 2; // mid là chiều cao cần tìm
        if (check(h, T, mid, sum))        // nếu chiều cao cần tìm thỏa mãn, cập nhật high
            high = mid - 1;
        else
            high = low + 1; // ngược lại, cập nhật low
    }

    cout << high << '\n';
}