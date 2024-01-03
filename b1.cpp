#include "utils.h"

struct SegmentTree
{
    vector<int> st;

    SegmentTree(vector<int> &input)
    {
        int n = input.size();
        st.resize(4 * n);
        build(input, 1, 0, n - 1);
    }

    void build(vector<int> &input, int node, int l, int r)
    {
        if (l == r) // node lá
        {
            st[node] = input[l];
            return;
        }
        int mid = (l + r) / 2;
        build(input, 2 * node, l, mid);         // cây con trái
        build(input, 2 * node + 1, mid + 1, r); // cây con phải

        st[node] = gcd(st[2 * node], st[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            st[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);

        st[node] = gcd(st[2 * node], st[2 * node + 1]);
    }

    int query(int node, int l, int r, int i, int j)
    {
        if (l > j || r < i) // không giao nhau
            return 0;
        if (l >= i && r <= j) // [l, r] nằm trong đoạn [i, j]
            return st[node];

        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, i, j);
        int right = query(2 * node + 1, mid + 1, r, i, j);

        return gcd(left, right);
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    SegmentTree segmentTree(a);
    for (int i = 0; i + k - 1 < n; i++)
        res = max(res, segmentTree.query(1, 0, n - 1, i, i + k - 1));

    cout << res << '\n';
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}

/*
Đề bài: Tìm ước chung lớn nhất tối đa của k phần tử liên tiếp trong một mảng

Ý tưởng: Vì UCLN(a, b, c) = UCLN(UCLN(a, b), c) nên ta có thể dùng Sparse Table hoặc Segment Tree để giải quyết bài toán này.

Duyệt 1 vòng lặp để tìm UCLN tối đa của k phần tử liên tiếp trong mảng.
Để tính UCLN tối đa của k phần tử liên tiếp trong mảng, ta có thể dùng Sparse Table hoặc Segment Tree.

+ Cách tạo segment tree:
    - Tạo một mảng 1 chiều st[] với st[i] là UCLN của đoạn [i, j] (đoạn có độ dài 2^i) trong mảng input.
    - Với mỗi i từ 1 đến log2(n), ta có thể tính st[i] từ st[i - 1] và st[i - 1].

Segment tree tốt hơn do có thể update giá trị của một phần tử trong mảng input


Gọi phần tử lớn nhất của mảng là m và độ dài của mảng là n
Độ phức tạp: O(nlogm) + O((n-k+1)*logn * logm)
            Xây cây + Duyệt + duyệt cây + tìm GCD

Không gian: O(4*n) = O(n) do mảng st[] có độ dài 4*n
*/
