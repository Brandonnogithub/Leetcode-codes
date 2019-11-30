#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int temp = 0;
        int temp2 = numRows - 2;
        int one_loop = numRows + temp2;
        int n = s.length() / one_loop;
        int left = s.length() - n * one_loop;
        int line = 0;
        int base = one_loop * n;

        string res;

        // First line
        for (int i = 0; i < n; ++i) {
            res += s[temp];
            temp += one_loop;
        }
        if (left > line) {
            res += s[base + line];
        }

        temp2 = temp2 * 2 + 1;
        // Inner lines
        for (line++; line < numRows-1; ++line) {
            temp = 0;
            for (int j = 0; j < n; ++j) {
                res += s[temp + line];
                res += s[temp + temp2];
                temp += one_loop;
            }
            if (left > line) {
                res += s[base + line];
            }
            if (left > temp2) {
                res += s[base + temp2];
            }
            temp2--;
        }

        // Final line
        temp = line;
        for (int i = 0; i < n; ++i) {
            res += s[temp];
            temp += one_loop;
        }
        if (left > line) {
            res += s[base + line];
        }

        return res;
    }
};


class Solution2 {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};


int main() {
    string s = "PAYPALISHIRING";
    int rownumber = 3;
    Solution sol = Solution();
    string res = sol.convert(s, rownumber);
    cout << res << endl;
    return 0;
}