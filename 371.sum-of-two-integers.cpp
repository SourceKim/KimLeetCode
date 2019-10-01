/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.77%)
 * Likes:    866
 * Dislikes: 1614
 * Total Accepted:    149.6K
 * Total Submissions: 294.6K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {

        // 设 a 为 5  0101
        // 设 b 为 1  0001
        // 应得    6  0110

        while (b != 0) // 现在用 b 来存储要进位的值
        {
            int carry = a & b; // 要进位的值   0001
            a = a^b; // 做异或，求得不进位的结果, 存到 a 中 0100
            b = (unsigned int)carry << 1; // 进位的值左移一位，在下一次 "&" 的时候把他 & 进去
        }
        
        return a;
        
    }
};
// @lc code=end

