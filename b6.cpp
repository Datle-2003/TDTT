// Cho k dãy gồm các số nguyên đã được sắp xếp sẵn theo thứ tự tăng dần trong mỗi danh sách. Các phần tử trong dãy có thể có cùng giá trị.
// Yêu cầu: Hãy gộp tất cả k dãy này lại thành một danh sách đã được sắp xếp theo thứ tự tăng dần.

#include "utils.h"

struct Tuple
{
    int value;
    int listIndex;
    int elementIndex;

    Tuple(int value, int listIndex, int elementIndex) : value(value), listIndex(listIndex), elementIndex(elementIndex) {}

    bool operator>(const Tuple &other) const
    {
        return value > other.value;
    }

    bool operator<(const Tuple &other) const
    {
        return value < other.value;
    }
};

void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> input;
    while (n--)
    {
        string tmp;
        getline(cin, tmp);
        stringstream ss(tmp);
        vector<int> ans;
        int num;
        while (ss >> num)
        {
            ans.push_back(num);
        }
        input.push_back(ans);
    }

    vector<int> res;
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;

    for (int i = 0; i < input.size(); i++)
    {
        pq.push(Tuple(input[i][0], i, 0));
    }

    while (!pq.empty())
    {
        Tuple top = pq.top();
        pq.pop();
        res.push_back(top.value);

        if (top.elementIndex + 1 < input[top.listIndex].size())
            pq.push(Tuple(input[top.listIndex][top.elementIndex + 1], top.listIndex, top.elementIndex + 1));
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}