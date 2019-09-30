/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.67%)
 * Likes:    5177
 * Dislikes: 201
 * Total Accepted:    641.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // DP
        // 以下 dpMax 可以理解为，以 i 结尾的数的局部最大值

        int globalMax = nums[0]; // 当前最大值 (全局
        int dpMax = nums[0]; // 以遍历时候 nums[i] 为最后一个数时候最大值（局部

        // 遍历数组每一个值
        for (int i = 1; i < nums.size(); i++)
        {
            if (dpMax >0) { // 如果上一步的最大值大于 0，那 这一步的最大值 = 这一步的值 + 上一步的最大值
                dpMax = nums[i] + dpMax;
            } else { // 如果上一步的最大值小于等于 0，那么 这一步的最大值 = 这一步的值
                dpMax = nums[i];
            }

            // 检查全局最大值和局部最大值
            globalMax = max(dpMax, globalMax);
        }
        
        return globalMax;
    }
};
// @lc code=end

