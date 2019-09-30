/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.55%)
 * Likes:    2892
 * Dislikes: 109
 * Total Accepted:    536.2K
 * Total Submissions: 871.1K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // 使用 XOR （AKA 异或、^

        // 异或的性质： （都可以使用二进制异或原理去推导，即 00 11 为 0， 01 为 1
        // 1. 多个元素异或，交换顺序结果不变
        // 2. 0 异或任何数，仍然等于任何数

        // 这一题就成为： a0^a1^a2...^an^y^a0....^an == an^a0...an^an^y == 0^y == y

        int res = nums[0];
        for (int i=1; i<nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end

