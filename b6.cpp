
#include "utils.h"

struct Node
{
    int value;
    int listIndex;
    int elementIndex;

    Node(int value, int listIndex, int elementIndex) : value(value), listIndex(listIndex), elementIndex(elementIndex) {}

    bool operator>(const Node &other) const
    {
        return value > other.value;
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
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int i = 0; i < input.size(); i++)
    {
        pq.push(Node(input[i][0], i, 0)); 
    }

    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();
        res.push_back(top.value);

        if (top.elementIndex + 1 < input[top.listIndex].size())
            pq.push(Node(input[top.listIndex][top.elementIndex + 1], top.listIndex, top.elementIndex + 1));
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

/*
Đề bài: gộp k dãy số đã sắp xếp thành 1 dãy số đã sắp xếp

Ý tưởng: Sử dụng min-heap để lấy ra phần tử nhỏ nhất trong k dãy số đã sắp xếp
        Sau đó thêm phần tử đó vào dãy số kết quả, thêm phần tử tiếp theo của dãy số đó vào min-heap
        Lặp lại cho đến khi min-heap rỗng

Độ phức tạp: O(klogk) + O(n*k*logk)

Không gian: O(k)
*/