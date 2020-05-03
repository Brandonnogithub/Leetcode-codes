#include <unordered_map>
#include <iostream>
using namespace std;

/*
1. using a "hash table/unordered map" to store the positon of each char (recent appear postion). O(n)  it's similar to the Problem 1
*/

 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        unordered_map<char, int> last_pos;
        int max_len = 0;
        int tmp_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last_pos.find(s[i]) == last_pos.end()) {
                last_pos[s[i]] = i;
            } else {
                if (last_pos[s[i]] >= start) {
                    tmp_len = i - start;
                    if (tmp_len > max_len) {
                        max_len = tmp_len;
                    }
                    start = last_pos[s[i]] + 1;
                }
                last_pos[s[i]] = i;
            }
        }
        tmp_len = s.size() - start;
        return max(tmp_len, max_len);
    }
};

int main() {
    Solution sol = Solution();
    string input = "aabaab!bb";
    int len = sol.lengthOfLongestSubstring(input);
    cout << len << endl;
    return 0;
}