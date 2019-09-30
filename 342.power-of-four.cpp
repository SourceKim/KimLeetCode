/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (40.75%)
 * Likes:    345
 * Dislikes: 159
 * Total Accepted:    124.5K
 * Total Submissions: 305.4K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {

        // 使用二进制

        // 4  -- 0000100
        // 16 -- 0010000
        // 64 -- 1000000

        // cout << bitset<32>(num) << endl;

        if (num == 1) {
            return true;
        }

        if (num < 4) { // 排除
            return false;
        }

        if ((num & (num - 1)) != 0) { // 不是 2 的 power
            return false;
        } else {
            return (num & 0x55555555) == num; // 0x55555555 二进制是 01010101010101010101010101010101
        }
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    bool res = sol->isPowerOfFour(16);
    cout << res << endl;
    return 0;
}


