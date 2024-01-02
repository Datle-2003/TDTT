// Cho xâu A và xâu B chỉ gồm các chữ cái thường. Xâu B được gọi là xuất hiện tại vị trí i của xâu A nếu:
// A1= B1, Ai+1= B2, ..., Ai+lenB-1= Blen(B)
// Yêu cầu: Hãy tìm tất cả các vị trí mà xâu B xuất hiện trong A.

#include "utils.h"

vector<int> BoyerMoore(string &text, string &pattern)
{
    vector<int> ans;
    int n = text.size(), m = pattern.size();
    vector<int> badMatchTable(256, m);

    for (int i = 0; i < m - 1; i++)
        badMatchTable[pattern[i]] = m - i - 1; // all the characters in pattern except the last one

    int i = m - 1;
    while (i < n)
    {
        int j = m - 1;
        while (j >= 0 && text[i] == pattern[j])
        {
            i--;
            j--;
        }

        if (j == -1)
        {
            ans.push_back(i + 1);
            i += m + 1;
        }
        else
            i += badMatchTable[text[i]];
    }
    return ans;
}

vector<int> KMP(string &text, string &pattern)
{
    int n = text.size(), m = pattern.size();
    vector<int> ans;

    vector<int> prefix(m, 0);
    for (int i = 1; i < m; i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = prefix[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        prefix[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j])
            j++;
        if (j == m)
        {
            ans.push_back(i - m + 1);
            j = prefix[j - 1];
        }
    }

    return ans;
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;

    // vector<int> ans = BoyerMoore(text, pattern);

    vector<int> ans = KMP(text, pattern);
    for (int i : ans)
        cout << i << " ";
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}