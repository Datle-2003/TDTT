#include "utils.h"

//Cho n đoạn liên tiếp, đoạn thứ i có chiều cao hi. Chiều cao chênh lệch giữa 2 đoạn liên tiếp không vượt quá 1 đơn vị. Ta cần đào sâu xuống càng sâu càng tốt. Ta dự định chi T đồng cho công việc này. Chi phí giảm chiều cao của một đoạn đi 1 đơn vị là 1 đồng.
// Yêu cầu: Cho biết các chiều cao h1, h2, …, hn và chi phí T. Hãy xác định chiều cao thấp nhất (đào sâu nhất) mà ta có thể đào được với T đồng mà vẫn đảm bảo chênh lệch giữa 2 đoạn liên tiếp không quá 1 đơn vị.


bool check(vector<int> &h, int T, long long mid){
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, T;
    cin >> n >> T;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // using binary search
    long long low = -1e18;
    long long high = *min_element(h.begin(), h.end());

    while (low <= high){
        long long mid = (low + high) / 2;

        if (check(h, T, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << low << "\n";

    
}