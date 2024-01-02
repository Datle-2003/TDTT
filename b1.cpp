#include "utils.h"

struct SparseTable
{
    vector<vector<int>> st;

    SparseTable(vector<int> &input)
    {
        int n = input.size();
        st.resize(log2(n) + 1, vector<int>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = input[i];

        for (int i = 1; i <= log2(n); i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            { // j -> j + 2^i - 1
                st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int k = log2(r - l + 1);                       // example: l = 0, r = 2 -> k = 1
        return gcd(st[k][l], st[k][r - (1 << k) + 1]); // split [l, r] into [l, l + 2^k - 1] and [r - 2^k + 1, r]
    }
};

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
        if (l == r)
        {
            st[node] = input[l];
            return;
        }

        int mid = (l + r) / 2;
        build(input, 2 * node, l, mid);
        build(input, 2 * node + 1, mid + 1, r);

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
        if (l > j || r < i)
            return 0;
        if (l >= i && r <= j)
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
    for (auto &x : a)
        cin >> x;

    SparseTable st(a);

    int res = 0;
    // for (int i = 0; i + k - 1 < n; i++)
    // {
    //     res = max(res, st.query(i, i + k - 1));
    // }

    SegmentTree seg(a);
    for (int i = 0; i + k - 1 < n; i++)
    {
        res = max(res, seg.query(1, 0, n - 1, i, i + k - 1));
    }

    cout << res << endl;
}

// solving problem not nessessarily continous
void solve2()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            dp[i][j] = max(dp[i - 1][j], gcd(dp[i - 1][j - 1], a[i]));
        }
    }

    // print dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    cout << dp[n][k] << endl;
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // solve2();
}