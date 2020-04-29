#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
1. brute-force: O(n^2)

2. O(nlogn) can we just go through it once ? store the previous numbers by map

3. map use red black tree, O(logn) 
   unorder_map use hash table, O(1) , but more memory than map
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> memory;
        for (int i = 0; i < nums.size(); i++) {
            if (memory.find(target - nums[i]) == memory.end()) {
                memory[nums[i]] = i;
            } else {
                res.push_back(memory[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            
        }
        return res;
    }
};


int main() {
    Solution2 sol = Solution2();
    vector<int> nums = vector<int>();
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    vector<int> res = sol.twoSum(nums, target);
    cout << res[0] << "\t" << res[1] << endl;
    return 0;
}