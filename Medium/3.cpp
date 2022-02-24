// 3. Longest Substring Without Repeating Characters
// 02/24/2022 22:24	Accepted	7 ms	6.8 MB	cpp

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int is_used[200] = {0,};
        int cnt = 0;
        int ans = 0;
        int start = 0;
        for(int i=0;i<len;i++) {
            if(!is_used[s[i]]) {
                is_used[s[i]] = i+1;
                cnt++;
            }
            else {
                int temp = is_used[s[i]];
                for(int j=start;j<is_used[s[i]];j++) {
                    is_used[s[j]] = 0;
                    cnt--;
                }
                start = temp;
                is_used[s[i]] = i+1;
                cnt++;
            }
            if(cnt > ans) ans = cnt;
        }
        return ans;
    }
};