// 22. Generate Parentheses
// 02/25/2022 21:45	Accepted	14 ms	17.9 MB	cpp

#include <string>
#include <vector>
using namespace std;

vector<string> v;

class Solution
{
public:
    void get(int idx, int N, int open, int close, string s)
    {
        if (idx == 2 * N)
        {
            v.push_back(s);
            return;
        }
        if (open < N)
        {
            s[idx] = '(';
            get(idx + 1, N, open + 1, close, s);
        }
        if (close < open)
        {
            s[idx] = ')';
            get(idx + 1, N, open, close + 1, s);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        v.resize(0);
        string s;
        s.resize(n * 2);
        get(0, n, 0, 0, s);
        return v;
    }
};