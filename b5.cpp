#include "utils.h"

const int base = 31;
const int modulo = 1e9 + 7;

int get_hash(string &s)
{
    int n = s.size();
    int hash_value = 0;
    for (int i = 0; i < n; i++)
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * (int)pow(base, n - i - 1)) % modulo;
    }
}

int update_hash(int old_hash, int old_char, int new_char, int n)
{
    int new_hash = (old_hash - (old_char - 'a' + 1) * (int)pow(base, n - 1)) * base + (new_char - 'a' + 1);
    return new_hash;
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;

    vector<int> ans;
    int n = text.size(), m = pattern.size();
    int pattern_hash = get_hash(pattern);
    int text_hash = get_hash(text.substr(0, m));

    for (int i = 0; i <= n - m; i++)
    {
        if (text_hash == pattern_hash)
        {
            bool isSame = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                ans.push_back(i);
        }
        if (i < n - m)
            text_hash = update_hash(text_hash, text[i], text[i + m], m);
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}

/*
Đề bài: Cho 2 xâu S và T, tìm tất cả các vị trí xuất hiện của T trong S.

Ý tưởng: Dùng thuật toán Rabin-Karp
        Dùng 1 hàm rolling hash để tính hash của các xâu con có độ dài m của S
        Nếu hash của xâu con bằng hash của T thì kiểm tra xem xâu con đó có bằng T không
        Nếu bằng thì lưu lại vị trí của xâu con đó
        Cập nhật hash cho xâu con tiếp theo
Độ phức tạp: O(n + m) cho trường hợp tốt nhất, xảy ra khi hàm hash không bị collision
             O(n * m) cho trường hợp xấu nhất, xảy ra khi hàm hash xảy ra collision

Không gian: O(1)
*/




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


/*
Ý tưởng dùng thuật toán Boyer-Moore: Bỏ qua các phần không cần thiết khi so sánh 2 xâu bằng việc di chuyển nhiều bước nhất sau mỗi lần so sánh
Quy tắc di chuyển:
Nếu kí tự không khớp, tìm ký tự trong T có nằm ở đâu trong P hay không, nếu có -> dịch tới vị trí cuối cùng của ký tự đó, nếu không, dịch tới vị trí cuối cùng của T(sau vị trí không khớp)

Độ phức tạp: O(mn) khi tất cả ký tự trong P và T đều giống nhau
            O(n/m) khi tất cả ký tự trong P và T đều khác nhau

Không gian: O(1)
*/
