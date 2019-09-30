/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (40.97%)
 * Likes:    273
 * Dislikes: 492
 * Total Accepted:    171.1K
 * Total Submissions: 417.7K
 * Testcase Example:  '6'
 *
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 * Example 1:
 * 
 * 
 * Input: 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 14
 * Output: false 
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * 
 * 
 * Note:
 * 
 * 
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
 * 
 */

#include <iostream>
// @lc code=start

class Solution {
public:
    bool isUgly(int num) {

        if (num <= 0) {
            return false;
        }
        // std::cout << num << std::endl;
        return slim(num) == 1;
        
    }

private:
    int slim(int num) {

        if (num % 2 == 0) {
            return slim(num / 2);
        } else if (num % 3 == 0) {
            return slim(num / 3);
        } else if (num % 5 == 0) {
            return slim(num / 5);
        }

        return num;

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    bool res = sol->isUgly(56);
    std::cout << res << std::endl;
    return 0;
}
