// 20. Valid Parentheses
// 02/24/2022 02:57	Accepted	0 ms	6.4 MB	cpp

#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.size();

        stack<int> stc;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(')
                stc.push(1);
            else if (s[i] == ')')
            {
                if (stc.empty() || stc.top() != 1)
                    return 0;
                else
                    stc.pop();
            }
            else if (s[i] == '[')
                stc.push(2);
            else if (s[i] == ']')
            {
                if (stc.empty() || stc.top() != 2)
                    return 0;
                else
                    stc.pop();
            }
            else if (s[i] == '{')
                stc.push(3);
            else if (s[i] == '}')
            {
                if (stc.empty() || stc.top() != 3)
                    return 0;
                else
                    stc.pop();
            }
        }
        if (!stc.empty())
            return 0;
        return 1;
    }
};